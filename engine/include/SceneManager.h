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
        
        void EnterScene(Scene* scene);
        void Update();
    private:
        Scene* current_scene_;
    };
}

#endif //STATEMACHINE_H
