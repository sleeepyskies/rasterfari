#include "objparser.hpp"
#include "rasterfari.hpp"
#include "renderer.hpp"
#include <string>

/**
 * Entry point of rasterfari.
 */
int main(int argc, char **argv) {
    /*
    // read scene file from command line args
    std::string sceneFile = (argc > 1) ? argv[1] : "TODO: default scene path";

    // init engine and run
    Rasterfari rasterfari(sceneFile);
    rasterfari.run();
    */
    Logger::setLevel(LogLevel::Trace);

    std::string faceObj =
        "D:/dev/c++ projects/graphics/rasterfari/models/african_head.obj";

    TGAImage img = TGAImage(600, 600, TGAImage::Format::RGB);

    auto mesh      = Mesh();
    auto objParser = ObjParser();
    objParser.loadObj(faceObj, mesh);

    auto renderer = Renderer();
    renderer.fillFaces(mesh, img);

    return 0;
}