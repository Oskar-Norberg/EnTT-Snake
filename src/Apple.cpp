//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "Apple.h"

#include "Components/Engine/BoxCollider.h"
#include "Components/Engine/SpriteRenderer.h"

namespace Game
{
    Apple::Apple(entt::registry* registry, Vector2 position) : position_(position), Entity(registry)
    {
        AddComponent<Components::SpriteRenderer>();
        AddComponent<Components::BoxCollider>(Rectangle{0, 0, 0.25f, 0.25f});
    }
}
