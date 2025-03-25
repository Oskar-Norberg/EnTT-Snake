//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeGame.h"

#include "WindowProperties.h"
#include <raylib.h>
#include <vector>

#include "Scenes/MainMenuScene.h"
#include "Scenes/PlayingScene.h"

namespace Snake
{
    SnakeGame::SnakeGame() : states_(), stateMachine_()
    {
        InitWindow(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, Window::WINDOW_TITLE);

        states_.push_back(new Scenes::MainMenuScene());
        states_.push_back(new Scenes::PlayingScene());

        stateMachine_.AddScenes(states_);
        // TODO: Temporarily sets state to playing state
        stateMachine_.SwitchScene(typeid(Scenes::PlayingScene));
    }

    SnakeGame::~SnakeGame()
    {
        CloseWindow();

        for (auto state : states_)
        {
            delete state;
        }
    }

    void SnakeGame::Run()
    {
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            stateMachine_.Update();
            
            EndDrawing();
        }
    }
}
