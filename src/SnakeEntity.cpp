//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeEntity.h"

#include "BoxCollider.h"
#include "Components/PlayerInput.h"
#include "Components/PlayerMovement.h"
#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"

namespace Snake
{
    SnakeEntity::SnakeEntity(entt::registry* registry) : Entity(registry){
        AddComponent<Components::Transform>(Vector2{0, 0}, 0.25f, 45.0f);
        AddComponent<Components::SpriteRenderer>();
        AddComponent<Components::PlayerInput>();
        AddComponent<Components::PlayerMovement>(0.2f);
        AddComponent<Components::BoxCollider>(Rectangle{0, 0, 0.25f, 0.25f});
    }
    
    SnakeEntity::~SnakeEntity(){
        registry_->destroy(entity_);
    }
}
