//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include "CustomComponent.h"

#include "Components/Engine/PlayerInput.h"
#include "Components/Engine/Transform.h"

namespace Components
{
    struct PlayerMovement : public Components_Custom::CustomComponent
    {
        PlayerMovement() = default;

        void OnUpdate(float deltaTime) override
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
