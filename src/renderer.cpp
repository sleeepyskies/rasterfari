#include "renderer.hpp"

void Renderer::line(int x0, int y0, int x1, int y1, ImageBuffer &ib,
                    Color color) {
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
            ib.pixel(y, x) = color;
        } else {
            ib.pixel(x, y) = color;
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx * 2;
        }
    }
}

void Renderer::triangle(Vertex3f v1, Vertex3f v2, Vertex3f v3, ImageBuffer &ib,
                        Color color) {
    // order vertices by y value such that v1 has lowest y val, v3 has largest
    if (v1.y() >= v2.y()) {
        Vertex3f temp = v1;
        v1            = v2;
        v2            = temp;
    }
    if (v2.y() >= v3.y()) {
        Vertex3f temp = v2;
        v2            = v3;
        v3            = temp;
    }
    if (v1.y() >= v2.y()) {
        Vertex3f temp = v1;
        v1            = v2;
        v2            = temp;
    }

    // fill first half of triangle
    float slope1 = (v2.x() - v1.x()) / (v2.y() - v1.y());
    float slope2 = (v3.x() - v1.x()) / (v3.y() - v1.y());

    float x1 = v1.x();
    float x2 = v1.x();

    for (int yLvl = v1.y(); yLvl <= v2.y(); yLvl++) {
        line(x1, yLvl, x2, yLvl, ib, color);
        x1 += slope1;
        x2 += slope2;
    }

    // fill second half of triangle
    float slope3 = -slope2;
    float slope4 = -(v3.x() - v2.x()) / (v3.y() - v2.y());

    float x3 = v3.x();
    float x4 = v3.x();

    for (int yLvl = v3.y(); yLvl >= v2.y(); yLvl--) {
        line(x3, yLvl, x4, yLvl, ib, color);
        x3 += slope3;
        x4 += slope4;
    }
}

void Renderer::wireFrame(Mesh &mesh, ImageBuffer &ib) {
    int W = ib.width();
    int H = ib.height();

    // render the mesh, disregarding the z dimension
    const auto white = Color(255, 255, 255, 255);
    unsigned int max = mesh.faceCount();
    for (unsigned int i = 0; i < max; i++) {
        Vertex3u face = mesh.iFace(i);

        Vertex3f v1 = mesh.iVertex(face.x());
        Vertex3f v2 = mesh.iVertex(face.y());
        Vertex3f v3 = mesh.iVertex(face.z());

        // from v1 => v2
        line((v1.x() + 1) * W / 2.f,
             H - (v1.y() + 1) * H / 2.f,
             (v2.x() + 1) * W / 2.f,
             H - (v2.y() + 1) * H / 2.f,
             ib,
             white);
        // from v1 => v3
        line((v1.x() + 1) * W / 2.f,
             H - (v1.y() + 1) * H / 2.f,
             (v3.x() + 1) * W / 2.f,
             H - (v3.y() + 1) * H / 2.f,
             ib,
             white);
        // from v2 => v3
        line((v2.x() + 1) * W / 2.f,
             H - (v2.y() + 1) * H / 2.f,
             (v3.x() + 1) * W / 2.f,
             H - (v3.y() + 1) * H / 2.f,
             ib,
             white);
    }
}

void Renderer::fillFaces(Mesh &mesh, ImageBuffer &ib) {
    int W = ib.width();
    int H = ib.height();

    int faceMax = mesh.faceCount();
    for (unsigned int i = 0; i < faceMax; i++) {
        Vertex3u face = mesh.iFace(i);

        Vertex3f v1 = mesh.iVertex(face.x());
        Vertex3f v2 = mesh.iVertex(face.y());
        Vertex3f v3 = mesh.iVertex(face.z());

        v1.setX((v1.x() + 1) * W / 2);
        v2.setX((v2.x() + 1) * W / 2);
        v3.setX((v3.x() + 1) * W / 2);
        v1.setY(H - (v1.y() + 1) * H / 2);
        v2.setY(H - (v2.y() + 1) * H / 2);
        v3.setY(H - (v3.y() + 1) * H / 2);

        float l = std::min((v1.z() + v2.z() + v3.z()) * 500 / 3.f, 255.f);

        Color c = Color(l);

        triangle(v1, v2, v3, ib, c);
    }
}