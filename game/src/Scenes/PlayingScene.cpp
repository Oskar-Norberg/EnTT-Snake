//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "Scenes/PlayingScene.h"

#include "SceneManager.h"
#include <iostream>

namespace Components
{
    struct BoxCollider;
}

namespace Scenes
{
    PlayingScene::PlayingScene() : Scene(), snake_(&registry_), apple_(&registry_, Core_Utils::Vector2{5, 5})
    {
    }

    void PlayingScene::Enter(SceneManager* state_machine_)
    {
        std::cout << "Enter Playing State" << std::endl;
    }

    void PlayingScene::Tick(SceneManager* state_machine_)
    {
        Scene::Tick(state_machine_);
    }

    void PlayingScene::Exit(SceneManager* state_machine_)
    {
        std::cout << "Exit Playing State" << std::endl;
    }
}
