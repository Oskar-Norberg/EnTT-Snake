//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <typeindex>
#include <unordered_map>
#include <vector>

namespace Scenes
{
    class Scene;
    
    class SceneManager
    {
    public:
        SceneManager() = default;
        ~SceneManager() = default;

        void AddScene(Scene* scene);
        void AddScenes(const std::vector<Scene*>& scenes);
        void SwitchScene(const std::type_index& type);
        void Update();
    private:
        std::pmr::unordered_map<std::type_index, Scene*> scene_map;
        void EnterScene(Scene* scene);

        Scene* current_scene_;
    };
}

#endif //STATEMACHINE_H
