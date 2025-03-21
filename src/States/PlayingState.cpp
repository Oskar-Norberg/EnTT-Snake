//
// Created by Oskar.Norberg on 2025-03-13.
//

#include "States/PlayingState.h"

#include "StateMachine.h"
#include <iostream>

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
        auto group = registry_.group<Component::Transform>(entt::get<Components::SpriteRenderer>);

        for (auto entity : group)
        {
            auto& transform = group.get<Component::Transform>(entity);
            auto& sprite_renderer = group.get<Components::SpriteRenderer>(entity);

            sprite_renderer.Render(transform);
        }
    }

    void PlayingState::Exit(StateMachine* state_machine_)
    {
        std::cout << "Exit Playing State" << std::endl;
    }
}
