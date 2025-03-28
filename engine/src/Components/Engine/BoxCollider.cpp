//
// Created by Oskar.Norberg on 2025-03-25.
//

#include "Components/Engine/BoxCollider.h"

#include "Entity.h"
#include <raylib.h>
#include "Components/Engine/Transform.h"

namespace Components
{
    bool BoxCollider::CheckCollision(const BoxCollider& other) const
    {
        auto* transform = entity_->GetComponent<Transform>();
        Core_Utils::Vector2 position = transform->position;
        float colliderSize = transform->scale;

        auto* otherTransform = other.entity_->GetComponent<Transform>();
        Core_Utils::Vector2 otherPosition = otherTransform->position;
        float otherColliderSize = otherTransform->scale;

        auto collider = Rectangle{position.x, position.y, colliderSize, colliderSize};
        auto otherCollider = Rectangle{otherPosition.x, otherPosition.y, otherColliderSize, otherColliderSize};
    
        return CheckCollisionRecs(collider, otherCollider);
    }
}