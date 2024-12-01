#include "display.hpp"

namespace Rasterfari {

Window::Window() {
    // init SDL_Window
    // TODO: clean this up, define constants or something
    m_window = SDL_CreateWindow("Rasterfari",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                600,
                                600,
                                0);
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

    Logger::Info("Rasterfari window has succesfully been initialised.");
}

Window::~Window() {
    if (m_window) {
        SDL_DestroyWindow(m_window);
    } else {
        Logger::Warn(
            "Window member in Rasterfari Window does not exist and cannot be "
            "destroyed: ",
            SDL_GetError());
    }
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    } else {
        Logger::Warn(
            "Renderer member in Rasterfari Window does not exist and cannot be "
            "destroyed: ",
            SDL_GetError());
    }
}

int Window::width() const { return m_screen->w; }

int Window::height() const { return m_screen->h; }

void Window::display(ImageBuffer &imageBuffer) {
    if (SDL_BlitSurface(imageBuffer.buffer(), nullptr, m_screen, nullptr) !=
        0) {
        Logger::Error("Could not blit image buffer to display surface: ",
                      SDL_GetError());
    }

    if (SDL_UpdateWindowSurface(m_window) != 0) {
        Logger::Error("Could not copy window surface to screen: ",
                      SDL_GetError());
        return;
    }
}

ImageBuffer::ImageBuffer(Window &window) {
    const int width  = window.width();
    const int height = window.height();

    m_buffer =
        SDL_CreateRGBSurface(0, width, height, 32, rMask, gMask, bMask, aMask);

    if (!m_buffer) {
        Logger::Error("Could not create member surface in ImageBuffer: ",
                      SDL_GetError());
    }

    Logger::Info("Rasterfari ImageBuffer has succesfully been initialised.");
}

ImageBuffer::~ImageBuffer() { SDL_FreeSurface(m_buffer); }

void ImageBuffer::ready() const {
    if (SDL_LockSurface(m_buffer) != 0)
        Logger::Warn("Failed to lock the SDL surface: ", SDL_GetError());
}

void ImageBuffer::unReady() const { SDL_UnlockSurface(m_buffer); }

Color &ImageBuffer::pixel(int x, int y) {
    // Compute the address of the pixel in the buffer.
    uint8_t *pixelAddress = (uint8_t *) m_buffer->pixels + y * m_buffer->pitch +
                            x * m_buffer->format->BytesPerPixel;

    // Cast the address to a 32-bit integer pointer and return a reference.
    return *(Color *) pixelAddress;
}

SDL_Surface *ImageBuffer::buffer() { return m_buffer; }

int ImageBuffer::width() const { return m_buffer->w; }

int ImageBuffer::height() const { return m_buffer->h; }
} // namespace Rasterfari