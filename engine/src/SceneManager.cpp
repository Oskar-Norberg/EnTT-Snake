//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "SceneManager.h"
#include "Scene.h"

#include <iostream>

namespace Scenes
{
    void SceneManager::Update(){
        if (current_scene_ == nullptr)
        {
            std::cout << "No scene set!" << std::endl;
            return;
        }

        current_scene_->Tick(this);
    }

    void SceneManager::EnterScene(Scene* scene)
    {
        if (current_scene_ != nullptr)
            current_scene_->Exit(this);
    
        current_scene_ = scene;
        current_scene_->Enter(this);
    }
}