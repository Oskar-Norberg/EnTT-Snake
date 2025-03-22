//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include "CustomComponent.h"
#include "../Engine/Component.h"
#include "../Engine/PlayerInput.h"
#include "../Engine/Transform.h"

namespace Components
{
    struct PlayerMovement : public Components_Custom::CustomComponent
    {
        explicit PlayerMovement(Game::Entity* entity, const float speed) :
        CustomComponent(entity),
        speed_(speed),
        transform_(entity->GetComponent<Transform>()),
        playerInput_(entity->GetComponent<PlayerInput>())
        {
        }
        
        PlayerMovement(Game::Entity* entity) : PlayerMovement(entity, 1.0f)
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
