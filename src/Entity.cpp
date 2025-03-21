//
// Created by Oskar.Norberg on 2025-03-21.
//

#include "Entity.h"

#include "Components/SpriteRenderer.h"
#include "Components/Updateable.h"

namespace Components
{
    struct Transform;
}

namespace Game
{
    Entity::Entity(entt::registry* registry) : registry_(registry), updateables_()
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

    void Entity::Update(float deltaTime)
    {
        for (auto updateable : updateables_)
            updateable->Update();
    }

    void Entity::Render()
    {
        if (HasComponent<Components::SpriteRenderer>())
        {
            auto spriteRenderer = GetComponent<Components::SpriteRenderer>();
            auto transform = GetComponent<Components::Transform>();

            // shits being copied
            spriteRenderer->Render(*transform);
        }
    }

    Entity* Entity::GetEntity()
    {
        return this;
    }
}
