//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "State.h"

namespace States
{
    class MainMenuState : public State
    {
    public:
        MainMenuState();
    
        void Enter(StateMachine* state_machine_) override;
        void Tick(StateMachine* state_machine_) override;
        void Exit(StateMachine* state_machine_) override;
    };
}

#endif //MAINMENUSTATE_H
