#pragma once

#include "logger.hpp"
#include <SDL.h>

class ImageBuffer;
class Window;

/**
 * @brief The class used to represent color in Rasterfari. Rasterfari uses the
 * RGBA fomat, where each color is 32-bits.
 */
struct Color {
    /// @brief The color data.
    union {
        struct {
            uint8_t r, g, b, a; // raw color channles
        };
        uint32_t value; // full color value
    };

    /// @brief Creates a color witht the provided values.
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : r(r), g(g), b(b), a(a) {}

    /// @brief Creates a grayscale color with the given brightness.
    Color(uint8_t s) : r(s), g(s), b(s), a(s) {}

    /// @brief Creates a black color.
    Color() : value(0) {}
};

/**
 * @brief This class wraps SDL_Window and SDL_Renderer. Is used as a way to draw
 * to the window simply by just providing an ImageBuffer.
 */
class Window {
private:
    /// @brief The actual SDL_Window to draw to.
    SDL_Window *m_window;
    /// @brief The SDL_Renderer used to draw to the window.
    SDL_Renderer *m_renderer;
    /// @brief The SDL_Surface associated with this window.
    SDL_Surface *m_screen;

public:
    /// @brief The Window default constructor. Inits the window and renderer.
    Window();
    /// @brief Correctly cleans up SDL members.
    ~Window();

    /// @brief Returns the width of the window in pixels.
    int width() const;
    /// @brief Returns the height of the window in pixels.
    int height() const;

    /// @brief Used to draw the provided ImageBuffer to the window.
    void display(ImageBuffer &imageBuffer);
};

/**
 * @brief This class is essentially a wrapper for the SDL2 struct SDL_Surface.
 * This class is used to make cpp style programming more feasible, as well as to
 * make using SDL2 a little simpler.
 */
class ImageBuffer {
private:
    /// @brief The SDL2 surface that holds the buffer data.
    SDL_Surface *m_buffer;

    // TODO - maybe put these in a macro?

    /// @brief The red mask, indictaes which bits are used to store red data.
    uint32_t rMask = 0xFF000000;
    /// @brief The green mask, indictaes which bits store green data.
    uint32_t gMask = 0x00FF0000;
    /// @brief The blue mask, indictaes which bits are used to store blue data.
    uint32_t bMask = 0x0000FF00;
    /// @brief The alpha mask, indictaes which bits are store alpha data.
    uint32_t aMask = 0x000000FF;

public:
    /// @brief Constructor for the ImageBuffer. Essentially copies the
    /// surface from the given window.
    ImageBuffer(Window &window);

    /// @brief Destructor for ImageBuffer.
    ~ImageBuffer();

    /// @brief Returns a reference to the pixel at the given coordinates. Can be
    /// used for quick accesing to avoid overhead when drawing to the
    /// ImageBuffer.
    const uint32_t &pixel(int x, int y);

    /// @brief Used to return a pointer to the SDL_Surface. Should only be
    /// used for blitting the surface to the window.
    SDL_Surface *buffer();

    /// @brief Returns the height of this ImageBuffer in pixels.
    int height() const;
    /// @brief Returns the width of this ImageBuffer in pixels.
    int width() const;
};