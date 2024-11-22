#include "objparser.hpp"

bool ObjParser::loadObj(const std::string &fileName, Mesh &mesh) {
    // create a new ifstream to read from .obj file
    std::ifstream in;
    in.open(fileName);
    if (in.fail()) { // opening the file failed
        Logger::Fatal("Could not load the file: ", fileName);
        return false;
    }

    // keep reading from file until eof or error
    std::string token;
    in >> token;
    while (in.good()) {
        if (token == "v") {
            if (!readVertices(in, mesh, token)) {
                std::cout << "Encountered issue reading vertices " << fileName
                          << std::endl;
                return false;
            }
        } else if (token == "vt") {
            if (!readTextures(in, mesh, token)) {
                std::cout << "Encountered issue reading textures " << fileName
                          << std::endl;
                return false;
            }
        } else if (token == "vn") {
            if (!readNormals(in, mesh, token)) {
                std::cout << "Encountered issue reading normals " << fileName
                          << std::endl;
                return false;
            }
        } else if (token == "f") {
            if (!readFaces(in, mesh, token)) {
                std::cout << "Encountered issue reading faces " << fileName
                          << std::endl;
                return false;
            }
        } else if (token == "g" || token == "#" || token == "s") {
            // skip line for now
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            in >> token;
        } else {
            std::cout << "Invalid token encountered " << token << std::endl;
            return false;
        }
    }

    // parsing success
    return true;
}

bool ObjParser::readVertices(std::ifstream &in, Mesh &mesh,
                             std::string &token) {
    // assumes 3 float values for each vertex for now
    // also assumes no obj file issues
    do {
        float x, y, z;
        in >> x;
        in >> y;
        in >> z;
        mesh.emplaceVertex(x, y, z);
    } while (in >> token && token == "v");

    in.unget();
    return true;
}

bool ObjParser::readTextures(std::ifstream &in, Mesh &mesh,
                             std::string &token) {
    do {
        // skip line for now
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (in >> token && token == "vt");

    return true;
}

bool ObjParser::readNormals(std::ifstream &in, Mesh &mesh, std::string &token) {
    do {
        // skip line for now
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (in >> token && token == "vn");

    return true;
}

bool ObjParser::readFaces(std::ifstream &in, Mesh &mesh, std::string &token) {
    // only vertex data for now
    do {
        unsigned int v1, v2, v3;

        // store entire line after 'f'
        std::string line;
        std::getline(in, line);
        std::stringstream sStream = std::stringstream(line);

        std::string facePart; // String to hold each face part

        // Read each vertex data (e.g., "24/1/24") and extract only the vertex
        // index
        sStream >> facePart; // "24/1/24"
        v1 = std::stoi(facePart.substr(
            0, facePart.find('/'))); // Get the first number (vertex index)

        sStream >> facePart; // "25/2/25"
        v2 = std::stoi(facePart.substr(
            0, facePart.find('/'))); // Get the first number (vertex index)

        sStream >> facePart; // "26/3/26"
        v3 = std::stoi(facePart.substr(
            0, facePart.find('/'))); // Get the first number (vertex index)

        mesh.emplaceFace(v1, v2, v3); // Add the face to the mesh with only
                                      // vertex indices

    } while (in >> token && token == "f");

    return true;
}