#include "imagebuffer.hpp"

ImageBuffer::ImageBuffer(Window &window) {
    // TODO
}

ImageBuffer::~ImageBuffer() { SDL_FreeSurface(m_buffer); }