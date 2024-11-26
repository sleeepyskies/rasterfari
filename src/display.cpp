#include "display.hpp"

Window::Window() {
    // init SDL_Window
    if (!m_window) {
        Logger::Error("SDL window could not be created: ", SDL_GetError());
        return;
    }

    // init SDL_Renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer) {
        Logger::Error("SDL renderer could not be created: ", SDL_GetError());
        return;
    }

    // init SDL_Surface
    m_screen = SDL_GetWindowSurface(m_window);
    if (!m_screen) {
        Logger::Error("SDL surface could not be fetched from window: ",
                      SDL_GetError());
        return;
    }
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}

const void Window::display(ImageBuffer &imageBuffer) {
    SDL_BlitSurface(imageBuffer.buffer(), nullptr, m_screen, nullptr);
    SDL_UpdateWindowSurface(m_window);
}

ImageBuffer::ImageBuffer(Window &window) { m_buffer = SDL_CreateRGBSurface(); }

ImageBuffer::~ImageBuffer() { SDL_FreeSurface(m_buffer); }