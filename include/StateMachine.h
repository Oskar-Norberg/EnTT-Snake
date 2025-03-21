//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <typeindex>
#include <unordered_map>
#include <vector>

namespace States
{
    class State;
    
    class StateMachine
    {
    public:
        StateMachine() = default;
        ~StateMachine() = default;

        void AddState(State* state);
        void AddStates(const std::vector<State*>& states);
        void SwitchState(const std::type_index& type);
        void Update();
    private:
        std::pmr::unordered_map<std::type_index, State*> state_map_;
        void EnterState(State* state);

        State* current_state_;
    };
}

#endif //STATEMACHINE_H
