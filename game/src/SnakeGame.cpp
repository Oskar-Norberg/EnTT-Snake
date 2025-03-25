//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeGame.h"

#include "Scenes/MainMenuScene.h"
#include "Scenes/PlayingScene.h"

namespace Snake
{
    SnakeGame::SnakeGame() : playing_scene_(nullptr)
    {
        playing_scene_ = new Scenes::PlayingScene();
        
        engine_ = Core::Engine();
        engine_.SetScene(playing_scene_);
    }

    SnakeGame::~SnakeGame()
    {
    }

    void SnakeGame::Run()
    {
        engine_.Run();
    }
}
