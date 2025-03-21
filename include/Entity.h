//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "SnakeEntity.h"

namespace Game
{
     class Entity
    {
    public:
        Entity() = default;
        virtual ~Entity() = default;

         entt::entity GetEntity() const { return entity; }
     private:
         entt::entity entity;
    };
}

#endif //ENTITY_H
