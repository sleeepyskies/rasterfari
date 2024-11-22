#pragma once

#include "item.hpp"
#include "mathy.hpp"
#include <vector>

/**
 * A struct representing some model consisting of triangles.
 */
struct Mesh : public Item {
private:
    // A vector holding all vertices in the model.
    std::vector<Vertex3f> m_vertices;
    // A vector holding the indices of the vertices that form a face.
    std::vector<Vertex3u> m_faces;

public:
    // Default constructor.
    Mesh();

    // Adds a new vertex to the models list.
    void emplaceVertex(float x, float y, float z);

    // Adds a new face to the models list.
    void emplaceFace(unsigned int v1, unsigned int v2, unsigned int v3);

    // Gets the i-th face of the model.
    Vertex3u iFace(unsigned int index);

    // Gets the i-th vertex of the model.
    Vertex3f iVertex(unsigned int index);

    // Returns the total number of faces in the model.
    unsigned int faceCount();
};