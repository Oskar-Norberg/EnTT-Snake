//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeGame.h"

#include "WindowProperties.h"
#include <raylib.h>
#include <vector>

#include "States/MainMenuState.h"
#include "States/PlayingState.h"

namespace Snake
{
    SnakeGame::SnakeGame() : states_(), stateMachine_()
    {
        InitWindow(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, Window::WINDOW_TITLE);

        states_.push_back(new States::MainMenuState());
        states_.push_back(new States::PlayingState());

        stateMachine_.AddStates(states_);
        // TODO: Temporarily sets state to playing state
        stateMachine_.SwitchState(typeid(States::PlayingState));
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
