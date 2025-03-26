//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "Apple.h"

#include "Components/MoveOnCollision.h"
#include "Components/Engine/BoxCollider.h"
#include "Components/Engine/SpriteRenderer.h"

namespace Game
{
    Apple::Apple(entt::registry* registry, Core_Utils::Vector2 position) : position_(position), Entity(registry)
    {
        auto* transform = GetComponent<Components::Transform>();
        transform->scale = 50.0f;
        
        AddComponent<Components::SpriteRenderer>();
        AddComponent<Components::BoxCollider>();
        AddComponent<MoveOnCollision>();
    }
}
