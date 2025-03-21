//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "StateMachine.h"

#include <iostream>

#include "State.h"

namespace States
{
    StateMachine::StateMachine(const std::vector<State*> &states)
    {
        for (State* state : states)
        {
            state_map_[typeid(*state)] = state;
        }

        current_state_ = nullptr;
    }

    void StateMachine::Tick(){
        if (current_state_ == nullptr)
        {
            std::cout << "No state set!" << std::endl;
            return;
        }

        current_state_->Tick(this);
    }

    void StateMachine::SwitchState(const std::type_index& type)
    {
        if (state_map_.contains(type))
        {
            EnterState(state_map_[type]);
        }else
        {
            std::cout << "State not found!" << std::endl;
        }
    }

    void StateMachine::EnterState(State* state)
    {
        if (current_state_ != nullptr)
            current_state_->Exit(this);
    
        current_state_ = state;
        current_state_->Enter(this);
    }
}