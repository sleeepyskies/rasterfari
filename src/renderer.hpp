#pragma once

#include "display.hpp"
#include "mathy.hpp"
#include "mesh.hpp"
#include <random>

namespace Rasterfari {

class Renderer {
private:
public:
    Renderer() {}

    // TODO SORT THIS CLASS OUT

    void line(int x0, int y0, int x1, int y1, ImageBuffer &ib, Color color);

    void triangle(Vertex3f v1, Vertex3f v2, Vertex3f v3, ImageBuffer &ib,
                  Color color);

    void wireFrame(Mesh &mesh, ImageBuffer &ib);

    void fillFaces(Mesh &mesh, ImageBuffer &ib);
};

} // namespace Rasterfari