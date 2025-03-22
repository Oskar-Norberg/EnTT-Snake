//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "States/PlayingState.h"

#include "StateMachine.h"
#include <iostream>

#include "../../include/Components/Engine/BoxCollider.h"

namespace Components
{
    struct BoxCollider;
}

namespace States
{
    PlayingState::PlayingState() : State(), snake_(&registry_), apple_(&registry_, Vector2{5, 5})
    {
    }

    void PlayingState::Enter(StateMachine* state_machine_)
    {
        std::cout << "Enter Playing State" << std::endl;
    }

    void PlayingState::Tick(StateMachine* state_machine_)
    {
        State::Tick(state_machine_);
    }

    void PlayingState::Exit(StateMachine* state_machine_)
    {
        std::cout << "Exit Playing State" << std::endl;
    }
}
