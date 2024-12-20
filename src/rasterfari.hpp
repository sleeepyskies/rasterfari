/**
 * @file rasterfari.hpp
 * @brief The main engine of the rasterizer
 */

#pragma once

#define SDL_MAIN_HANDLED

#include "display.hpp"
#include "logger.hpp"
#include "mesh.hpp"      // temp, remove later
#include "objparser.hpp" // temp, remove later
#include "renderer.hpp"
#include <SDL.h>

namespace Rasterfari {

/**
 * @brief The main part of the Rasterfari raserization engine.
 */
class Rasterfari {
private:
    /// @brief The window on which everything is rendered!
    Window m_window;
    /// @brief The scene that is being rendered. @todo Add
    // Scene m_scene;
    /// @brief Class for handling all user input. @todo Add
    // InputHandler inputHandler;
    /// @brief Class responsible for drawing drawing eveything to the window.
    Renderer m_renderer;

    /// @brief Runs the main loop of the engine.
    void run();

public:
    /// @brief Default constructor for the Rasterfari engine.
    /// @param sceneFile the file path to the scene to be rendered.
    Rasterfari(std::string sceneFile);

    /// @brief Destructor for the Rasterfari engine. Properly ends the engine.
    ~Rasterfari();
};
} // namespace Rasterfari