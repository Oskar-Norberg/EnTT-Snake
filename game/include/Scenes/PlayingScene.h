//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "Scene.h"

#include "Entity.h"

#include "SnakeEntity.h"
#include "Apple.h"

namespace Scenes
{
    class PlayingScene : public Scene
    {
    public:
        PlayingScene();
    
        void Enter(SceneManager* state_machine_) override;
        void Tick(SceneManager* state_machine_) override;
        void Exit(SceneManager* state_machine_) override;
        
    private:
        Snake::SnakeEntity snake_;
        Game::Apple apple_;
        std::vector<Game::Entity*> entities_;
    };
}

#endif //PLAYINGSTATE_H
