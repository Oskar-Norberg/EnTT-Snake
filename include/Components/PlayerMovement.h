//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include "Component.h"
#include "PlayerInput.h"
#include "Transform.h"

namespace Components
{
    struct PlayerMovement : public Component, public Updateable
    {
        explicit PlayerMovement(entt::registry* registry, Game::Entity* entity, const float speed) :
        Component(registry, entity),
        speed_(speed),
        transform_(entity->GetComponent<Transform>()),
        playerInput_(entity->GetComponent<PlayerInput>())
        {
        }
        
        PlayerMovement(entt::registry* registry, Game::Entity* entity) : PlayerMovement(registry, entity, 1.0f)
        {
        }

        void Update() override
        {
            transform_->position.x += playerInput_->direction_.x * speed_;
            transform_->position.y += playerInput_->direction_.y * speed_;
        }

        float speed_;

    private:
        Transform* transform_;
        PlayerInput* playerInput_;
    };
}

#endif //PLAYERMOVEMENT_H
