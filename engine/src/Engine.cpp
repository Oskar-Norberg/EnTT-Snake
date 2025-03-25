//
// Created by Oskar.Norberg on 2025-03-25.
//

#include "Engine.h"

#include "WindowProperties.h"
#include "raylib.h"

namespace Core
{
    Engine::Engine() : sceneManager_()
    {
        InitWindow(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, Window::WINDOW_TITLE);
    }

    Engine::~Engine()
    {
    }

    void Engine::SetScene(Scenes::Scene* scene)
    {
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
