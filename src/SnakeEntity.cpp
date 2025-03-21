//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "SnakeEntity.h"

#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"

namespace Snake
{
    SnakeEntity::SnakeEntity(entt::registry* registry){
        registry_ = registry;

        auto entity = registry_->create();
        registry_->emplace<Component::Transform>(entity);
        registry_->emplace<Components::SpriteRenderer>(entity);

        entity_ = entity;
    }
    SnakeEntity::~SnakeEntity(){
        registry_->destroy(entity_);
    }
}
