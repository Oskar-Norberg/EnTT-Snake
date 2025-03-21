//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef COMPONENT_H
#define COMPONENT_H
#include <entt.hpp>

namespace Components
{
    struct Component
    {
    public:
        Component(entt::registry* registry, Game::Entity* entity) : registry_(registry), entity_(entity) {}
    protected:
        entt::registry* registry_;
        Game::Entity* entity_;
    };
}

#endif //COMPONENT_H
