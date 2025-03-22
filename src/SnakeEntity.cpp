//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeEntity.h"

#include "../include/Components/Engine/BoxCollider.h"
#include "Components/Engine/PlayerInput.h"
#include "../include/Components/CustomComponent/PlayerMovement.h"
#include "Components/Engine/SpriteRenderer.h"

namespace Snake
{
    SnakeEntity::SnakeEntity(entt::registry* registry) : Entity(registry){
        AddComponent<Components::SpriteRenderer>();
        AddComponent<Components::PlayerInput>();
        AddComponent<Components::PlayerMovement>(0.2f);
        AddComponent<Components::BoxCollider>(Rectangle{0, 0, 0.25f, 0.25f});
    }
}
