#include "display.hpp"

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
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}

int Window::width() const { return m_screen->w; }

int Window::height() const { return m_screen->h; }

void Window::display(ImageBuffer &imageBuffer) {
    SDL_BlitSurface(imageBuffer.buffer(), nullptr, m_screen, nullptr);
    SDL_UpdateWindowSurface(m_window);
}

ImageBuffer::ImageBuffer(Window &window) {
    const int width  = window.width();
    const int height = window.height();

    m_buffer =
        SDL_CreateRGBSurface(0, width, height, 32, rMask, gMask, bMask, aMask);
}

ImageBuffer::~ImageBuffer() { SDL_FreeSurface(m_buffer); }

const uint32_t &ImageBuffer::pixel(int x, int y) {
    // Compute the address of the pixel in the buffer.
    uint8_t *pixelAddress = (uint8_t *) m_buffer->pixels + y * m_buffer->pitch +
                            x * m_buffer->format->BytesPerPixel;

    // Cast the address to a 32-bit integer pointer and return a reference.
    return *(uint32_t *) pixelAddress;
}

SDL_Surface *ImageBuffer::buffer() { return m_buffer; }

int ImageBuffer::width() const { return m_buffer->w; }

int ImageBuffer::height() const { return m_buffer->h; }