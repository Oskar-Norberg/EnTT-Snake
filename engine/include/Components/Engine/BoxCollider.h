//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

namespace Game
{
    class Entity;
}

#include "Components/Engine/Component.h"

namespace Components{
    struct BoxCollider : public Component
    {
        explicit BoxCollider(Game::Entity* entity) : Component(entity) {}

        // TODO: this function is going to be the slowest thing ever
        // TODO: It shouldn't really be here either? Maybe in a physics class?
        bool CheckCollision(const BoxCollider& other) const;
    };
}

#endif //BOXCOLLIDER_H
