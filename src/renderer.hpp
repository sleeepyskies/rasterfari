#pragma once

#include "mathy.hpp"
#include "mesh.hpp"
#include "tgaimage.hpp"
#include <random>

class Renderer {
private:
public:
    Renderer() {}

    // TODO SORT THIS CLASS OUT

    void line(int x0, int y0, int x1, int y1, TGAImage &img, TGAColor color);

    void triangle(Vertex3f v1, Vertex3f v2, Vertex3f v3, TGAImage &img,
                  TGAColor color);

    void wireFrame(Mesh &mesh, TGAImage &img);

    void fillFaces(Mesh &mesh, TGAImage &img);
};