//
// Created by Oskar.Norberg on 2025-03-25.
//

#include "Engine.h"

#include "Logger.h"
#include <raylib.h>
#include "WindowProperties.h"

namespace Core
{
    Engine::Engine() : sceneManager_()
    {
        Logging::Logger::Init();
        InitWindow(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, Window::WINDOW_TITLE);
    }

    Engine::~Engine()
    {
        Logging::Logger::Cleanup();
    }

    void Engine::SetScene(Scenes::Scene* scene)
    {
        // TODO: Add scene names for logging. Temporarily just get typeid name.
        RNGO_LOG_INFO(("Entering scene: " + std::string(typeid(scene).name())).c_str());
        sceneManager_.EnterScene(scene);
    }

    void Engine::Run()
    {
        Init();
        
        while (!WindowShouldClose())
        {
            BeginDrawing();
            sceneManager_.Update();
            EndDrawing();
        }

        CleanUp();
    }

    void Engine::Init()
    {
    }

    void Engine::CleanUp()
    {
    }
}
