#include "objparser.hpp"
#include <fstream>
#include <iostream>

bool ObjParser::loadObj(const std::string &fileName, Model &model) {
    return true;
    // create a new ifstream to read from .obj file
    std::ifstream fStream;
    fStream.open(fileName);
    if (fStream.fail()) // opening the file failed
        std::cout << "Could not open file " << fileName << std::endl;
    return false;

    // keep reading from file until eof or error
    while (fStream.good()) {
        char data = (char) fStream.peek();

        // determine what data chunk comes next
        switch (data) {
        case 'v':
            if (readVertices()) {
                std::cout << "Issue loading Vertices" << std::endl;
                return false;
            };
            break;
        case 'vt':
            if (readTexture()) {
                std::cout << "Issue loading Textures" << std::endl;
                return false;
            };
            break;
        case 'vn':
            if (readNormals()) {
                std::cout << "Issue loading Normals" << std::endl;
                return false;
            };
            break;
        case 'f':
            if (readFaces()) {
                std::cout << "Issue loading Faces" << std::endl;
                return false;
            };
            break;
        default:
            std::cout << "Could not determine data type of .obj file"
                      << std::endl;
            return false;
        }
    }
}