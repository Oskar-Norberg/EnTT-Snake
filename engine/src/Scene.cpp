//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "Scene.h"

#include "Components/CustomComponent/CustomComponent.h"
#include "Components/Engine/BoxCollider.h"
#include "Components/Engine/PlayerInput.h"
#include "Components/Engine/ScriptableComponent.h"
#include "Components/Engine/SpriteRenderer.h"
#include "Components/Engine/Transform.h"

namespace Scenes
{
    Scene::Scene() : registry_()
    {
    }

    Scene::~Scene()
    {
        auto customGroup = registry_.group<Components::ScriptableComponent>();
        
        for (auto entity : customGroup)
        {
            auto& scriptable = customGroup.get<Components::ScriptableComponent>(entity);
            if (scriptable.IsInstantiated())
                scriptable.OnDestroy();
        }
        registry_.clear();
    }

    void Scene::Tick(SceneManager* scene_manager){
        HandleInput();
        HandleCollisions();
        HandleScriptables();
        Render();
    }

    void Scene::HandleInput(){
        auto inputGroup = registry_.group<Components::PlayerInput>();
        
        for (auto entity : inputGroup)
        {
            auto& entityPlayerInput = inputGroup.get<Components::PlayerInput>(entity);
            entityPlayerInput.Poll();
        }
    }
    
    void Scene::HandleCollisions(){
        // TODO: Mark my words, this is gonna run like ass

        auto boxColliderGroup = registry_.group<Components::BoxCollider>();

        for (auto entity : boxColliderGroup)
        {
            auto& boxCollider = boxColliderGroup.get<Components::BoxCollider>(entity);
            
            for (auto otherEntity : boxColliderGroup)
            {
                if (otherEntity == entity)
                    continue;

                auto& otherBoxCollider = boxColliderGroup.get<Components::BoxCollider>(otherEntity);

                bool collided = boxCollider.CheckCollision(otherBoxCollider);

                if (collided)
                {
                    if (!registry_.any_of<Components::ScriptableComponent>(entity))
                        continue;
                    
                    auto& scriptable = registry_.get<Components::ScriptableComponent>(entity);
                    if (!scriptable.IsInstantiated())
                        continue;
                    
                    scriptable.OnCollision(otherEntity);
                }
            }
        }
    }
    
    void Scene::HandleScriptables(){
        auto customGroup = registry_.group<Components::ScriptableComponent>();
        
        for (auto entity : customGroup)
        {
            auto& scriptable = customGroup.get<Components::ScriptableComponent>(entity);

            if (!scriptable.IsInstantiated())
                scriptable.OnCreate();
            
            scriptable.OnUpdate(GetFrameTime());
        }
    }
    
    void Scene::Render(){
        ClearBackground(WHITE);
        
        auto renderingGroup = registry_.group<Components::Transform>(entt::get<Components::SpriteRenderer>);
        
        for (auto entity : renderingGroup)
        {
            auto& transform = renderingGroup.get<Components::Transform>(entity);
            auto& sprite_renderer = renderingGroup.get<Components::SpriteRenderer>(entity);
        
            sprite_renderer.Render(transform);
        }
    }
    
}
