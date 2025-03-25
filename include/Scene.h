//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef STATE_H
#define STATE_H

#include "SceneManager.h"

#include <entt.hpp>

namespace Scenes
{
    class Scene
    {
    public:
        Scene();
        ~Scene();
    
        virtual void Enter(SceneManager* scene_manager) = 0;
        virtual void Tick(SceneManager* scene_manager);
        virtual void Exit(SceneManager* scene_manager) = 0;
    protected:
        entt::registry registry_;
    private:
        void HandleInput();
        void HandleCollisions();
        void HandleScriptables();
        void Render();
    };
}

#endif //STATE_H
