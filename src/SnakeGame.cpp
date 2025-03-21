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
        InitWindow(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, Window::WINDOW_TITLE);
    }

    SnakeGame::~SnakeGame()
    {
        CloseWindow();
    }

    void SnakeGame::Run()
    {
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            EndDrawing();
        }
    }
}