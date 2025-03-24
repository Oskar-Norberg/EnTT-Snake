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
        explicit BoxCollider(Game::Entity* entity, Rectangle rectangle) : collider(rectangle), Component(entity) {}
        Rectangle collider;

        // TODO: this function is going to be the slowest thing ever
        // TODO: It shouldn't really be here either? Maybe in a physics class?
        bool CheckCollision(const BoxCollider& other) const
        {
            Vector2 position = entity_->GetComponent<Transform>()->position;
            Vector2 otherPosition = other.entity_->GetComponent<Transform>()->position;

            Rectangle collider = this->collider;
            Rectangle otherCollider = other.collider;

            collider.x = position.x;
            collider.y = position.y;

            otherCollider.x = otherPosition.x;
            otherCollider.y = otherPosition.y;
            
            return CheckCollisionRecs(collider, other.collider);
        }
    };
}

#endif //BOXCOLLIDER_H
