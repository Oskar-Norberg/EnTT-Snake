//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "States/PlayingState.h"

#include "StateMachine.h"
#include <iostream>

#include "BoxCollider.h"
#include "Components/PlayerInput.h"
#include "Components/PlayerMovement.h"
#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"

namespace Components
{
    struct BoxCollider;
}

namespace States
{
    PlayingState::PlayingState() : State(), registry_(), snake_(&registry_), apple_(&registry_, Vector2{5, 5})
    {
        
    }

    void PlayingState::Enter(StateMachine* state_machine_)
    {
        std::cout << "Enter Playing State" << std::endl;
    }

    void PlayingState::Tick(StateMachine* state_machine_)
    {
        HandleInput();
        HandleMovement();
        HandleCollisions();
        Render();
    }

    void PlayingState::Exit(StateMachine* state_machine_)
    {
        std::cout << "Exit Playing State" << std::endl;
    }

    void PlayingState::HandleInput()
    {
        auto inputGroup = registry_.group<Components::PlayerInput>();

        for (auto entity : inputGroup)
        {
            auto& entityPlayerInput = inputGroup.get<Components::PlayerInput>(entity);
            entityPlayerInput.Poll();
        }
    }

    void PlayingState::HandleMovement()
    {
        auto movementGroup = registry_.group<Components::PlayerMovement>(entt::get<Components::PlayerInput, Components::Transform>);

        for (auto entity : movementGroup)
        {
            auto& playerInput = movementGroup.get<Components::PlayerInput>(entity);
            auto& playerMovement = movementGroup.get<Components::PlayerMovement>(entity);
            auto& transform = movementGroup.get<Components::Transform>(entity);

            playerMovement.Update(playerInput, transform);
        }
    }

    // Terrible, terrible function.
    void PlayingState::HandleCollisions()
    {
        auto boxColliderGroup = registry_.group<Components::BoxCollider>(entt::get<Components::Transform>);
        std::vector<Components::BoxCollider> boxColliders;
        for (auto entity : boxColliderGroup)
        {
            auto& boxCollider = boxColliderGroup.get<Components::BoxCollider>(entity);
            boxColliders.push_back(boxCollider);
        }

        for (auto& boxCollider : boxColliders)
        {
            std::vector<Components::BoxCollider> collisions = boxCollider.CheckForCollisions(boxColliders);

            for (auto& collision : collisions)
            {
                std::cout << "Collision detected" << std::endl;
            }
        }
    }

    void PlayingState::Render()
    {
        auto renderingGroup = registry_.group<Components::Transform>(entt::get<Components::SpriteRenderer>);

        for (auto entity : renderingGroup)
        {
            auto& transform = renderingGroup.get<Components::Transform>(entity);
            auto& sprite_renderer = renderingGroup.get<Components::SpriteRenderer>(entity);

            sprite_renderer.Render(transform);
        }
    }
}
