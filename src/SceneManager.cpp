//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "SceneManager.h"
#include "Scene.h"

#include <iostream>

namespace Scenes
{
    void SceneManager::AddScene(Scene* scene)
    {
        scene_map[typeid(*scene)] = scene;
    }

    void SceneManager::AddScenes(const std::vector<Scene*>& scenes)
    {
        for (auto state : scenes)
            AddScene(state);
    }

    void SceneManager::Update(){
        if (current_scene_ == nullptr)
        {
            std::cout << "No scene set!" << std::endl;
            return;
        }

        current_scene_->Tick(this);
    }

    void SceneManager::SwitchScene(const std::type_index& type)
    {
        if (scene_map.contains(type))
        {
            EnterScene(scene_map[type]);
        }else
        {
            std::cout << "Scene not found!" << std::endl;
        }
    }

    void SceneManager::EnterScene(Scene* scene)
    {
        if (current_scene_ != nullptr)
            current_scene_->Exit(this);
    
        current_scene_ = scene;
        current_scene_->Enter(this);
    }
}