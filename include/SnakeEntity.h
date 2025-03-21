//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SNAKEENTITY_H
#define SNAKEENTITY_H

#include <entt.hpp>

#include "Entity.h"

namespace Snake
{
    class SnakeEntity : public Game::Entity
    {
    public:
        explicit SnakeEntity(entt::registry* registry);
        ~SnakeEntity();
    private:
        entt::entity entity_;
        entt::registry* registry_;
    };
}

#endif //SNAKEENTITY_H
