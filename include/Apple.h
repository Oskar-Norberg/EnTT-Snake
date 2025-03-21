//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef APPLE_H
#define APPLE_H
#include "Entity.h"
#include "raylib.h"

namespace Game
{
    class Apple : public Entity
    {
    public:
        explicit Apple(entt::registry* registry, Vector2 position);
    private:
        Vector2 position_;
    };
}

#endif //APPLE_H
