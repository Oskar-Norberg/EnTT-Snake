//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeGame.h"

#include "WindowProperties.h"
#include <raylib.h>

namespace Snake
{
    SnakeGame::SnakeGame()
    {
    }

    SnakeGame::~SnakeGame()
    {
    }

    void SnakeGame::Run()
    {
        InitWindow(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, Window::WINDOW_TITLE);
    
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            EndDrawing();
        }
    
        CloseWindow();
    }
}