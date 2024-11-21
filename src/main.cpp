#include "mathy.hpp"
#include "model.hpp"
#include "objparser.hpp"
#include "tgaimage.hpp"
#include <iostream>

const auto white = TGAColor(255, 255, 255, 255);
const auto red   = TGAColor(255, 0, 0, 255);

const int W = 600;
const int H = 600;

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    const int dx = x1 - x0;
    const int dy = y1 - y0;
    int derror2  = std::abs(dy) * 2;
    int error2   = 0;
    int y        = y0;
    for (int x = x0; x <= x1; x++) {
        if (steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx * 2;
        }
    }
}

int main(int argc, char **argv) {
    // make image
    TGAImage img = TGAImage(W, H, TGAImage::Format::RGB);

    // load model
    Model model       = Model();
    ObjParser oParser = ObjParser();
    if (!oParser.loadObj(
            "D:/dev/c++ projects/graphics/renderer/models/crate.obj", model)) {
        std::cout << "fail lol" << std::endl;
        return 1;
    }

    // render the model, disregarding the z dimension
    unsigned int max = model.faceCount();
    for (unsigned int i = 0; i < max; i++) {
        Vertex3u face = model.iFace(i);

        Vertex3f v1 = model.iVertex(face.x());
        Vertex3f v2 = model.iVertex(face.y());
        Vertex3f v3 = model.iVertex(face.z());

        // from v1 => v2
        line((v1.x() + 1) * W / 2.f,
             (v1.y() + 1) * H / 2.f,
             (v2.x() + 1) * W / 2.f,
             (v2.y() + 1) * H / 2.f,
             img,
             white);
        // from v1 => v3
        line((v1.x() + 1) * W / 2.f,
             (v1.y() + 1) * H / 2.f,
             (v3.x() + 1) * W / 2.f,
             (v3.y() + 1) * H / 2.f,
             img,
             white);
        // from v2 => v3
        line((v2.x() + 1) * W / 2.f,
             (v2.y() + 1) * H / 2.f,
             (v3.x() + 1) * W / 2.f,
             (v3.y() + 1) * H / 2.f,
             img,
             white);
    }

    img.flip_vertically();
    img.write_tga_file("output.tga");
    return 0;

    return 0;
}
