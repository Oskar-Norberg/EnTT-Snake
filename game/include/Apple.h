//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef APPLE_H
#define APPLE_H

#include "Entity.h"
#include "Vector2.h"

namespace Game
{
    class Apple : public Entity
    {
    public:
        explicit Apple(entt::registry* registry, Core_Utils::Vector2 position);
    private:
        Core_Utils::Vector2 position_;
    };
}

#endif //APPLE_H
