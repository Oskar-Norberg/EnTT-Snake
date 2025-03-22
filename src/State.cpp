//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "State.h"

#include "Components/Engine/SpriteRenderer.h"
#include "Components/Engine/Transform.h"

namespace States
{
    State::State() : registry_()
    {
    }

    void State::Tick(StateMachine* state_machine_){
        HandleInput();
        HandleMovement();
        HandleCollisions();
        HandleScriptables();
        Render();
    }

    void State::HandleInput(){
        // auto inputGroup = registry_.group<Components::PlayerInput>();
        //
        // for (auto entity : inputGroup)
        // {
        //     auto& entityPlayerInput = inputGroup.get<Components::PlayerInput>(entity);
        //     entityPlayerInput.Poll();
        // }
    }
    
    void State::HandleMovement(){
        // auto movementGroup = registry_.group<Components::PlayerMovement>(entt::get<Components::PlayerInput, Components::Transform>);
        //
        // for (auto entity : movementGroup)
        // {
        //     auto& playerInput = movementGroup.get<Components::PlayerInput>(entity);
        //     auto& playerMovement = movementGroup.get<Components::PlayerMovement>(entity);
        //     auto& transform = movementGroup.get<Components::Transform>(entity);
        //
        //     playerMovement.Update(playerInput, transform);
        // }
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
        // TODO: handle scriptables
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
