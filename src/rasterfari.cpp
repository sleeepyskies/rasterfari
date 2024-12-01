#include "rasterfari.hpp"

namespace Rasterfari {

Rasterfari::Rasterfari(std::string sceneFile = "defaultPath")
    : m_window(Window()) {
    // TDOD parseScene()

    // handle SDL init => returns 0 on success lol
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Logger::Error("SDL Video could not be initiaized: ", SDL_GetError());
        SDL_Quit();
        return;
    } else {
        Logger::Info("SDL Video has succesfully been initiaized!");
    }

    // init other member variables
    m_renderer = Renderer();

    run();
}

Rasterfari::~Rasterfari() { SDL_Quit(); }

void Rasterfari::run() {
    // The image buffer used to draw actual images onto, and then render onto
    // the screen via blitting.
    ImageBuffer imageBuffer = ImageBuffer(m_window);
    SDL_Event event; // used to handle any input events

    // TDOD Remove this, just used for testing rendering with SDL2
    ObjParser objParser = ObjParser();
    Mesh face           = Mesh();
    objParser.loadObj(
        "D:/dev/c++ projects/graphics/rasterfari/models/african_head.obj",
        face);

    bool running = true;
    while (running) {
        imageBuffer.ready(); // lock pixels.

        // handle all user input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false; // handle quit
        }

        // handle rendering
        m_renderer.wireFrame(face, imageBuffer);

        imageBuffer.unReady(); // unlock pixels
        m_window.display(imageBuffer);
    }
}
} // namespace Rasterfari