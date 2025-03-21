//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>

#include "Components/Collider.h"
#include "Components/SpriteRenderer.h"

namespace Game
{
    class Entity
    {
    public:
        explicit Entity(entt::registry* registry) : registry_(registry)
        {
            entity = registry_->create();

            if (entity == entt::null)
            {
                throw std::runtime_error("Failed to create entity");
            }
            
            // Add Transform component
            AddComponent<Components::Transform>();
        }
        
        virtual ~Entity()
        {
            registry_->destroy(entity);
        }

        template<typename T, typename... Args>
        void AddComponent(Args&&... args)
        {
            registry_->emplace<T>(entity, std::forward<Args>(args)...);
        }

        template<typename T>
        T& GetComponent()
        {
            return registry_->get<T>(entity);
        }

        template<typename T>
        bool HasComponent()
        {
            return registry_->any_of<T>(entity);
        }

        template<typename T>
        void RemoveComponent()
        {
            registry_->remove<T>(entity);
        }

        virtual void Update(float deltaTime) = 0;
        
        virtual void Render()
        {
            if (HasComponent<Components::SpriteRenderer>())
            {
                auto spriteRenderer = GetComponent<Components::SpriteRenderer>();
                auto transform = GetComponent<Components::Transform>();
                
                spriteRenderer.Render(transform);
            }
        }

        void OnCollision(Collider* collider);
    private:
        entt::registry* registry_;
        entt::entity entity;
    };
}

#endif //ENTITY_H
