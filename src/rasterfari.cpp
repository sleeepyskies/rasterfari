#include "rasterfari.hpp"

Rasterfari::Rasterfari() {
    Logger::setLevel(LogLevel::Debug); // init logLevel
    Logger::Warn("This has not been done yet!!!! Exiting program!");
    return;
}

Rasterfari::Rasterfari(std::string sceneFile) {
    // todo parseScene()
    initSDL();

    // TODO: render the image only once for now, will add more later
    SDL_Surface *screen      = SDL_GetWindowSurface(m_window);
    SDL_Surface *frameBuffer = SDL_CreateRGBSurface(0,
                                                    screen->w,
                                                    screen->h,
                                                    32,
                                                    0xFF000000,  // R mask
                                                    0x00FF0000,  // G mask
                                                    0x0000FF00,  // B mask
                                                    0x000000FF); // A mask

    uint8_t *pixels   = static_cast<uint8_t *>(frameBuffer->pixels);
    int pitch         = frameBuffer->pitch; // Pitch in bytes per row
    int bytesPerPixel = frameBuffer->format->BytesPerPixel; // Bytes per pixel

    // Calculate the correct position in memory
    for (int x = 20; x < 100; x++) {
        for (int y = 20; y < 100; y++) {
            uint8_t *pixel = pixels + y * pitch + x * bytesPerPixel;

            // Map a color (e.g., red)
            Uint32 color = 0xFF00FF00;

            // Set the pixel value (writes the color)
            *(Uint32 *) pixel = color; // Assuming 32-bit color format (RGBA
        }
    }

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

void Rasterfari::initSDL() {
    // handle SDL init => returns 0 on success lol
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        Logger::Info("SDL Video has succesfully been initiaized!");
    } else {
        Logger::Error("SDL Video could not be initiaized: ", SDL_GetError());
        SDL_Quit();
        return;
    }

    // window creation
    m_window = SDL_CreateWindow("rasterfari",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                600,
                                600,
                                0);
}