//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>
#include <iostream>


// Forward declarations
struct Collider;

namespace Components
{
    struct Updateable;
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

        virtual void Update(float deltaTime);
        
        virtual void Render();

        Entity* GetEntity();

        void OnCollision(Collider* collider);
    private:
        // TODO: Slight technical debt
        std::vector<Components::Updateable*> updateables_;
        entt::registry* registry_;
        entt::entity entity;
    };
}

#endif //ENTITY_H
