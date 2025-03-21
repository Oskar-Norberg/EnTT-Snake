//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include <entt.hpp>

#include "Apple.h"
#include "SnakeEntity.h"
#include "State.h"

namespace States
{
    class PlayingState : public State
    {
    public:
        PlayingState();
    
        void Enter(StateMachine* state_machine_) override;
        void Tick(StateMachine* state_machine_) override;
        void Exit(StateMachine* state_machine_) override;
        
    private:
        entt::registry registry_;
        Snake::SnakeEntity snake_;
        Game::Apple apple_;

        void HandleCollisions();
    };
}

#endif //PLAYINGSTATE_H
