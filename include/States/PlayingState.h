//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

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
    };
}

#endif //PLAYINGSTATE_H
