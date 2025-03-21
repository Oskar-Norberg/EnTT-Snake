//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H
#include <iostream>

#include "PlayerInput.h"
#include "Transform.h"

namespace Components
{
    struct PlayerMovement
    {
        PlayerMovement() : speed_(1.0f) {}
        explicit PlayerMovement(const float speed) : speed_(speed) {}

        void Update(const PlayerInput& playerInput, Transform& transform) const
        {
            transform.position.x += playerInput.direction_.x * speed_;
            transform.position.y += playerInput.direction_.y * speed_;
        }

        float speed_;
    };
}

#endif //PLAYERMOVEMENT_H
