#include "objparser.hpp"
#include "rasterfari.hpp"
#include "renderer.hpp"
#include <string>

/**
 * Entry point of Rasterfari.
 */
int main(int argc, char **argv) {
#ifdef NDEBUG
    Logger::setLevel(LogLevel::Info);
    Logger::Info("Running in release mode.");
#else
    Logger::setLevel(LogLevel::Debug);
    Logger::Info("Running in debug mode.");
#endif

    // read scene file from command line args
    std::string sceneFile =
        (argc > 1)
            ? argv[1]
            : "D:/dev/c++ projects/graphics/rasterfari/models/african_head.obj";

    // init engine and run
    Rasterfari rasterfari(sceneFile);

    return 0;
}