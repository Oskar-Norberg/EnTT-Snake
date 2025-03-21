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
        registry->emplace<Components::Transform>(entity, Vector2{0, 0}, 0.25f, 45.0f);
        registry->emplace<Components::SpriteRenderer>(entity);
        registry->emplace<Components::PlayerInput>(entity);
        registry->emplace<Components::PlayerMovement>(entity, 0.2f);
        registry->emplace<Components::BoxCollider>(entity, Rectangle{0, 0, 0.25f, 0.25f});

        entity_ = entity;
    }
    
    SnakeEntity::~SnakeEntity(){
        registry_->destroy(entity_);
    }
}
