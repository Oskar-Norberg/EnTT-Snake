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

         entt::entity GetEntity() const { return entity; }
     protected:
         entt::registry* registry_;
         entt::entity entity;
    };
}

#endif //ENTITY_H
