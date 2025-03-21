//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef COLLIDER_H
#define COLLIDER_H
#include "Component.h"

namespace Game
{
    class Entity;
}

namespace Components
{
    struct Collider : public Component
    {
        Collider(Game::Entity* entity) : Component(entity) {}
    };
}
#endif //COLLIDER_H
