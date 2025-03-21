//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>

namespace Game
{
    class Entity
    {
    public:
        explicit Entity(entt::registry* registry) : registry_(registry)
        {
            entity = registry_->create();
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
    private:
        entt::registry* registry_;
        entt::entity entity;
    };
}

#endif //ENTITY_H
