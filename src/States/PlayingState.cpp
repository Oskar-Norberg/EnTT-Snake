//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "States/PlayingState.h"

#include "StateMachine.h"
#include <iostream>

#include "Components/PlayerInput.h"
#include "Components/PlayerMovement.h"
#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"

namespace States
{
    PlayingState::PlayingState() : State(), registry_(), snake_(&registry_)
    {
        
    }

    void PlayingState::Enter(StateMachine* state_machine_)
    {
        std::cout << "Enter Playing State" << std::endl;
    }

    void PlayingState::Tick(StateMachine* state_machine_)
    {
        // Input handling
        auto inputGroup = registry_.group<Components::PlayerInput>();

        for (auto entity : inputGroup)
        {
            auto& entityPlayerInput = inputGroup.get<Components::PlayerInput>(entity);
            entityPlayerInput.Poll();
        }

        // Movement
        auto movementGroup = registry_.group<Components::PlayerMovement>(entt::get<Components::PlayerInput, Components::Transform>);

        for (auto entity : movementGroup)
        {
            auto& playerInput = movementGroup.get<Components::PlayerInput>(entity);
            auto& playerMovement = movementGroup.get<Components::PlayerMovement>(entity);
            auto& transform = movementGroup.get<Components::Transform>(entity);

            playerMovement.Update(playerInput, transform);
        }
        
        // Rendering
        auto renderingGroup = registry_.group<Components::Transform>(entt::get<Components::SpriteRenderer>);

        for (auto entity : renderingGroup)
        {
            auto& transform = renderingGroup.get<Components::Transform>(entity);
            auto& sprite_renderer = renderingGroup.get<Components::SpriteRenderer>(entity);

            sprite_renderer.Render(transform);
        }
    }

    void PlayingState::Exit(StateMachine* state_machine_)
    {
        std::cout << "Exit Playing State" << std::endl;
    }
}
