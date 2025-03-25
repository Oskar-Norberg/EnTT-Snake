//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "Entity.h"

#include "Transform.h"
#include "../../../cmake-build-debug/_deps/raylib_external-src/src/raylib.h"
#include "Components/Engine/Component.h"

namespace Components{
    struct BoxCollider : public Component
    {
        explicit BoxCollider(Game::Entity* entity) : Component(entity) {}

        // TODO: this function is going to be the slowest thing ever
        // TODO: It shouldn't really be here either? Maybe in a physics class?
        bool CheckCollision(const BoxCollider& other) const
        {
            auto* transform = entity_->GetComponent<Transform>();
            Vector2 position = transform->position;
            float colliderSize = transform->scale;

            auto* otherTransform = other.entity_->GetComponent<Transform>();
            Vector2 otherPosition = otherTransform->position;
            float otherColliderSize = otherTransform->scale;

            Rectangle collider = Rectangle{position.x, position.y, colliderSize, colliderSize};
            Rectangle otherCollider = Rectangle{otherPosition.x, otherPosition.y, otherColliderSize, otherColliderSize};
            
            return CheckCollisionRecs(collider, otherCollider);
        }
    };
}

#endif //BOXCOLLIDER_H
