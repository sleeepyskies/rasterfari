#pragma once

#include "window.hpp"
#include <SDL.h>

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
 * @brief This class is essentially a wrapper for the SDL2 struct SDL_Surface.
 * This class is used to make cpp style programming more feasible, as well as to
 * make using SDL2 a little simpler.
 */
class ImageBuffer {
private:
    /// @brief The SDL2 surface that holds the buffer data.
    SDL_Surface *m_buffer;

public:
    /// @brief Constructor for the ImageBuffer. Essentially copies the
    /// surface from the given window.
    ImageBuffer(Window &window);

    /// @brief Destructor for ImageBuffer.
    ~ImageBuffer();

    /// @brief Returns a reference to the pixel at the given coordinates. Can be
    /// used for quick accesing to avoid overhead when drawing to the
    /// ImageBuffer.
    uint32_t &pixel(int x, int y);

    /// @brief Returns the height of this ImageBuffer.
    int height();

    /// @brief Returns the width of this ImageBuffer.
    int width();
};