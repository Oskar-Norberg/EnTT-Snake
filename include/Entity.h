//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>
#include <iostream>

#include "Components/Engine/ScriptableComponent.h"

namespace Components
{
    struct Collider;
    struct Component;
}

namespace Components_Custom
{
    struct CustomComponent;
}

namespace Game
{
    class Entity
    {
    public:
        explicit Entity(entt::registry* registry);
        
        virtual ~Entity();

        template<typename T, typename... Args>
        void AddComponent(Args&&... args)
        {
            if constexpr (!std::is_base_of_v<Components::Component, T> && !std::is_base_of_v<Components_Custom::CustomComponent, T>)
                throw std::invalid_argument("Type T must inherit from Component");

            if constexpr (std::is_base_of_v<Components_Custom::CustomComponent, T>)
            {
                Components::ScriptableComponent& component = registry_->emplace<Components::ScriptableComponent>(entity, this);
                component.Bind<T>();
                component.InstantiationFunction();
            }
            else
            {
                registry_->emplace<T>(entity, this, std::forward<Args>(args)...);
            }

            // TODO: Add error handling
            // TODO: Return component
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

        Entity* GetEntity();

        void OnCollision(Components::Collider* collider);
    private:
        entt::registry* registry_;
        entt::entity entity;
    };
}

#endif //ENTITY_H
