//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <raylib.h>

#include "Component.h"
#include "raymath.h"
#include "Updateable.h"

namespace Components
{
    struct PlayerInput : public Component, public Updateable
    {
        PlayerInput(Game::Entity* entity, int up_key, int down_key, int left_key, int right_key)
        : up_key_(up_key),
        down_key_(down_key),
        left_key_(left_key),
        right_key_(right_key),
        direction_(),
        Component(entity)
        {}

        PlayerInput(Game::Entity* entity) : PlayerInput(entity, KEY_W, KEY_S, KEY_A, KEY_D)
        {}

        void Update() override
        {
            direction_ = {0.0f, 0.0f};
            
            if (IsKeyDown(up_key_))
            {
                direction_.y -= 1.0f;
            }
            
            if (IsKeyDown(down_key_))
            {
                direction_.y += 1.0f;
            }
            
            if (IsKeyDown(left_key_))
            {
                direction_.x -= 1.0f;
            }
            
            if (IsKeyDown(right_key_))
            {
                direction_.x += 1.0f;
            }

            direction_ = Vector2Normalize(direction_);
        }

        int up_key_;
        int down_key_;
        int left_key_;
        int right_key_;

        Vector2 direction_;
    };
}

#endif //PLAYERINPUT_H
