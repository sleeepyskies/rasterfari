#pragma once

#include "mathy.hpp"
#include "mesh.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <logger.hpp>
#include <sstream>
#include <string>
namespace Rasterfari {

/**
 * Parser for reading in .obj files.
 */
class ObjParser {
private:
    // Loads vertices from the input stream into the mesh.
    bool readVertices(std::ifstream &in, Mesh &mesh, std::string &token);
    // Loads textures from the input stream into the mesh.
    bool readTextures(std::ifstream &in, Mesh &mesh, std::string &token);
    // Loads normals from the input stream into the mesh.
    bool readNormals(std::ifstream &in, Mesh &mesh, std::string &token);
    // Loads faces from the input stream into the mesh.
    bool readFaces(std::ifstream &in, Mesh &mesh, std::string &token);

public:
    // Reads the data from the given file and loads into the provided mesh.
    bool loadObj(const std::string &filename, Mesh &mesh);
};
} // namespace Rasterfari