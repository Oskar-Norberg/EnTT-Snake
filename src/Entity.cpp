//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "Entity.h"

#include "Components/Engine/Transform.h"

namespace Game
{
    Entity::Entity(entt::registry* registry) : registry_(registry)
    {
        entity = registry_->create();

        if (entity == entt::null)
        {
            throw std::runtime_error("Failed to create entity");
        }
            
        // Add Transform component
        AddComponent<Components::Transform>();
    }

    Entity::~Entity()
    {
        registry_->destroy(entity);
    }

    Entity* Entity::GetEntity()
    {
        return this;
    }
}
