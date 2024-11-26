#include "rasterfari.hpp"

Rasterfari::Rasterfari()
    : m_window(Window()), m_imageBuffer(ImageBuffer(m_window)) {
    Logger::Warn("This has not been done yet!!!! Exiting program!");
    init();

    run();
    return;
}

Rasterfari::Rasterfari(std::string sceneFile)
    : m_window(Window()), m_imageBuffer(ImageBuffer(m_window)) {
    // TDOD parseScene()

    // handle SDL init => returns 0 on success lol
    init();

    run();
}

Rasterfari::~Rasterfari() { SDL_Quit(); }

void Rasterfari::run() {
    // todo, create a frameBuffer class/struct

    // loop
    SDL_Event event;
    bool running = true;
    while (running) {
        // handles quitting
        // TODO handle more events!! maybe we need an event handler?
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
}

void Rasterfari::init() {
    // handle SDL init => returns 0 on success lol
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        Logger::Info("SDL Video has succesfully been initiaized!");
    } else {
        Logger::Error("SDL Video could not be initiaized: ", SDL_GetError());
        SDL_Quit();
        return;
    }
}