#pragma once

#include "mathy.hpp"
#include <vector>

/**
 * A struct representing some model consisting of triangles.
 */
struct Model {
private:
    // A vector holding all vertices in the model.
    std::vector<Vertex3f> m_vertices;
    // A vector holding the indices of the vertices that form a face.
    std::vector<Vertex3i> m_faces;

public:
    // Default constructor.
    Model();

    // Gets the i-th face of the model.
    Vertex3i iFace(int index);
};