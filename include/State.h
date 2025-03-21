//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef STATE_H
#define STATE_H
#include "StateMachine.h"

namespace States
{
    class State
    {
    public:
        State();
    
        virtual void Enter(StateMachine* state_machine_) = 0;
        virtual void Tick(StateMachine* state_machine_) = 0;
        virtual void Exit(StateMachine* state_machine_) = 0;
    };
}

#endif //STATE_H
