//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>
#include <iostream>

#include "Components/Collider.h"
#include "Components/SpriteRenderer.h"
#include "Components/Updateable.h"

namespace Game
{
    class Entity
    {
    public:
        explicit Entity(entt::registry* registry) : registry_(registry), updateables_()
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
            auto* component = &registry_->emplace<T>(entity, std::forward<Args>(args)...);
            
            if (component == nullptr)
                assert("Failed to add component");

            if constexpr (std::is_base_of_v<Components::Updateable, T>)
                updateables_.push_back(component);
        }

        template<typename T>
        T* GetComponent()
        {
            return &registry_->get<T>(entity);
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

        virtual void Update(float deltaTime)
        {
            for (auto updateable : updateables_)
                updateable->Update();
        }
        
        virtual void Render()
        {
            if (HasComponent<Components::SpriteRenderer>())
            {
                auto spriteRenderer = GetComponent<Components::SpriteRenderer>();
                auto transform = GetComponent<Components::Transform>();

                // shits being copied
                spriteRenderer->Render(*transform);
            }
        }

        Entity* GetEntity()
        {
            return this;
        }

        void OnCollision(Collider* collider);
    private:
        // TODO: Slight technical debt
        std::vector<Components::Updateable*> updateables_;
        entt::registry* registry_;
        entt::entity entity;
    };
}

#endif //ENTITY_H
