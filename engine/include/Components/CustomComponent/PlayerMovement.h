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
        void OnCreation() override
        {
            transform_ = entity_->GetComponent<Transform>();
            playerInput_ = entity_->GetComponent<PlayerInput>();
            speed_ = 500.0f;
        }

        void OnUpdate(float deltaTime) override
        {
            transform_->position.x += playerInput_->direction_.x * speed_ * deltaTime;
            transform_->position.y += playerInput_->direction_.y * speed_ * deltaTime;
        }

        void OnCollision(Game::Entity* other) override
        {
            std::cout << "Collision detected" << std::endl;
        }

        float speed_;

    private:
        // TODO: Would it be possible to use references instead of raw pointers?
        Transform* transform_;
        PlayerInput* playerInput_;
    };
}

#endif //PLAYERMOVEMENT_H
