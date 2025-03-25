//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "Scenes/MainMenuScene.h"

#include <iostream>

namespace Scenes
{
    MainMenuScene::MainMenuScene()
    {
    }

    void MainMenuScene::Enter(SceneManager* state_machine_)
    {
        std::cout << "Enter Main Menu State" << std::endl;
    }

    void MainMenuScene::Tick(SceneManager* state_machine_)
    {
        std::cout << "Tick Main Menu State" << std::endl;
    }

    void MainMenuScene::Exit(SceneManager* state_machine_)
    {
        std::cout << "Exit Main Menu State" << std::endl;
    }
}