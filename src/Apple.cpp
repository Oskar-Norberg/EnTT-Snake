//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "Apple.h"

#include "BoxCollider.h"
#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"

namespace Game
{
    Apple::Apple(entt::registry* registry, Vector2 position) : position_(position), Entity(registry)
    {
        registry->emplace<Components::Transform>(entity, Vector2{0, 0}, 0.25f, 45.0f);
        registry->emplace<Components::SpriteRenderer>(entity);
        registry->emplace<Components::BoxCollider>(entity, Rectangle{0, 0, 0.25f, 0.25f});
    }
}
