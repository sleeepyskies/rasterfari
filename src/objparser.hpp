#include "mathy.hpp"
#include "model.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Parser for reading in .obj files.
 */
class ObjParser {
private:
    // Loads vertices from the input stream into the model.
    bool readVertices(std::ifstream &in, Model &model, std::string &token);
    // Loads textures from the input stream into the model.
    bool readTextures(std::ifstream &in, Model &model, std::string &token);
    // Loads normals from the input stream into the model.
    bool readNormals(std::ifstream &in, Model &model, std::string &token);
    // Loads faces from the input stream into the model.
    bool readFaces(std::ifstream &in, Model &model, std::string &token);

public:
    // Reads the data from the given file and loads into the provided model.
    bool loadObj(const std::string &filename, Model &model);
};