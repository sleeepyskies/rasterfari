#include "mathy.hpp"
#include "mesh.hpp"
#include "objparser.hpp"
#include "tgaimage.hpp"
#include <iostream>

/*
void renderFaces(TGAColor c) {
    TGAImage img(600, 600, TGAImage::Format::RGB);
    Vertex3f v1(150, 40, 50);
    Vertex3f v2(300, 300, 40);
    Vertex3f v3(40, 150, 10);

    line(v1.x(), v1.y(), v2.x(), v2.y(), img, red);
    line(v1.x(), v1.y(), v3.x(), v3.y(), img, red);
    line(v2.x(), v2.y(), v3.x(), v3.y(), img, red);

    // sort by y-axis
    if (v1.y() < v2.y()) rasterfari::swap(v1, v2);
    if (v2.y() < v3.x()) rasterfari::swap(v2, v3);
    if (v1.y() < v2.y()) rasterfari::swap(v1, v2);

    Vector3f vec12(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
    Vector3f vec13(v1.x() - v3.x(), v1.y() - v3.y(), v1.z() - v3.z());
    int dy        = v1.y() - v2.y();
    float scale12 = vec12.length() / dy;
    float scale13 = vec13.length() / dy;
    vec12.makeNormal();
    vec13.makeNormal();
    // iterate from v1 y to v2 y, filling in between the two lines.
    for (int yVal = v1.y(); yVal <= v2.y(); yVal++) {
        int xStart = (v1 + (vec12 * scale12 * (yVal - v1.y()))).y();
        int xEnd   = (v1 + (vec13 * scale13 * (yVal - v1.y()))).y();

        // fill in row
        while (xStart <= xEnd) {
            img.set(xStart, yVal, c);
            xStart++;
        }
    }

    img.set(10, 10, white);

    img.write_tga_file("output.tga");
}
*/
