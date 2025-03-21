//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "States/PlayingState.h"

#include "StateMachine.h"
#include <iostream>

namespace States
{
    PlayingState::PlayingState() : State()
    {
    }

    void PlayingState::Enter(StateMachine* state_machine_)
    {
        std::cout << "Enter Playing State" << std::endl;
    }

    void PlayingState::Tick(StateMachine* state_machine_)
    {
        std::cout << "Tick Playing State" << std::endl;
    }

    void PlayingState::Exit(StateMachine* state_machine_)
    {
        std::cout << "Exit Playing State" << std::endl;
    }
}