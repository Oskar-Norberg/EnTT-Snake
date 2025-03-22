//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef STATE_H
#define STATE_H

#include "StateMachine.h"

#include <entt.hpp>

namespace States
{
    class State
    {
    public:
        State();
    
        virtual void Enter(StateMachine* state_machine_) = 0;
        virtual void Tick(StateMachine* state_machine_);
        virtual void Exit(StateMachine* state_machine_) = 0;
    protected:
        entt::registry registry_;
    private:
        void HandleInput();
        void HandleCollisions();
        void HandleScriptables();
        void Render();
    };
}

#endif //STATE_H
