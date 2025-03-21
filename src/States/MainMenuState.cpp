//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "States/MainMenuState.h"

#include <iostream>

MainMenuState::MainMenuState()
{
}

void MainMenuState::Enter(StateMachine* state_machine_)
{
    std::cout << "Enter Main Menu State" << std::endl;
}

void MainMenuState::Tick(StateMachine* state_machine_)
{
    std::cout << "Tick Main Menu State" << std::endl;
}

void MainMenuState::Exit(StateMachine* state_machine_)
{
    std::cout << "Exit Main Menu State" << std::endl;
}
