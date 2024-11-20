#include "mathy.hpp"
#include "model.hpp"
#include <string>

/**
 * Parser for reading in .obj files. Currently can only parse the vertices and
 * faces contained in an .obj file.
 */
class ObjParser {
private:
public:
    // Reads the data from the given file and loads into the provided model.
    bool loadObj(const std::string &filename, Model &model);
};