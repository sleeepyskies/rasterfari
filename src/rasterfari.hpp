#pragma once

#define SDL_MAIN_HANDLED

#include "logger.hpp"
#include "renderer.hpp"
#include <SDL.h>

/**
 * @file rasterfari.hpp
 * @brief The main engine of the rasterizer
 */

/**
 * @brief The main part of the Rasterfari raserization engine.
 */
class Rasterfari {
private:
    /// @brief The window on which everything is rendered!
    /// @todo Move this to its own struct/class?
    SDL_Window *m_window = nullptr;
    /// @brief The SDL renderer. @todo Combine with m_window into class.
    SDL_Renderer *m_sdlrenderer;
    /// @brief The scene that is being rendered. @todo Add
    // Scene m_scene;
    /// @brief Class for handling all user input. @todo Add
    // InputHandler inputHandler;
    /// @brief Class responsible for drawing drawing eveything to the window.
    // Renderer m_renderer;

    /// @brief Runs the main loop of the engine.
    void run();
    /// @brief Handles the initialization of SDL2 within Rasterfari.
    void initSDL();

public:
    /// @brief Default constructor for the engine when no sceneFile is provided.
    Rasterfari();

    /// @brief Default constructor for the Rasterfari engine.
    /// @param sceneFile the file path to the scene to be rendered.
    Rasterfari(std::string sceneFile);

    /// @brief Destructor for the Rasterfari engine. Properly ends the engine.
    ~Rasterfari();
};
