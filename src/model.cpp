#include "model.hpp"

Model::Model() {}

Vertex3u Model::iFace(unsigned int index) { return m_faces[index]; }

Vertex3f Model::iVertex(unsigned int index) { return m_vertices[index]; }

void Model::emplaceVertex(float x, float y, float z) {
    m_vertices.emplace_back(Vertex3f(x, y, z));
}

void Model::emplaceFace(unsigned int v1, unsigned int v2, unsigned int v3) {

    m_faces.emplace_back(Vertex3u(v1 - 1, v2 - 1, v3 - 1));
}

unsigned int Model::faceCount() { return m_faces.size(); }