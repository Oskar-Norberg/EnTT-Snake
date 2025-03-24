//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "State.h"

#include "Components/CustomComponent/CustomComponent.h"
#include "Components/Engine/PlayerInput.h"
#include "Components/Engine/ScriptableComponent.h"
#include "Components/Engine/SpriteRenderer.h"
#include "Components/Engine/Transform.h"

namespace States
{
    State::State() : registry_()
    {
    }

    State::~State()
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

    void State::Tick(StateMachine* state_machine_){
        HandleInput();
        HandleCollisions();
        HandleScriptables();
        Render();
    }

    void State::HandleInput(){
        auto inputGroup = registry_.group<Components::PlayerInput>();
        
        for (auto entity : inputGroup)
        {
            auto& entityPlayerInput = inputGroup.get<Components::PlayerInput>(entity);
            entityPlayerInput.Poll();
        }
    }
    
    void State::HandleCollisions(){
        // TODO: Mark my words, this is gonna run like ass
        
        // auto boxColliderGroup = registry_.group<Components::BoxCollider>(entt::get<Components::Transform>);
        // std::vector<Components::BoxCollider> boxColliders;
        // for (auto entity : boxColliderGroup)
        // {
        //     auto& boxCollider = boxColliderGroup.get<Components::BoxCollider>(entity);
        //     boxColliders.push_back(boxCollider);
        // }
        //
        // for (auto& boxCollider : boxColliders)
        // {
        //     std::vector<Components::BoxCollider> collisions = boxCollider.CheckForCollisions(boxColliders);
        //
        //     for (auto& collision : collisions)
        //     {
        //         std::cout << "Collision detected" << std::endl;
        //     }
        // }
    }
    
    void State::HandleScriptables(){
        auto customGroup = registry_.group<Components::ScriptableComponent>();
        
        for (auto entity : customGroup)
        {
            auto& scriptable = customGroup.get<Components::ScriptableComponent>(entity);

            if (!scriptable.IsInstantiated())
            {
                scriptable.OnCreate();
            }
            
            scriptable.OnUpdate(GetFrameTime());
        }
    }
    
    void State::Render(){
        auto renderingGroup = registry_.group<Components::Transform>(entt::get<Components::SpriteRenderer>);
        
        for (auto entity : renderingGroup)
        {
            auto& transform = renderingGroup.get<Components::Transform>(entity);
            auto& sprite_renderer = renderingGroup.get<Components::SpriteRenderer>(entity);
        
            sprite_renderer.Render(transform);
        }
    }
    
}
