//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Component.h"
#include "raylib.h"

namespace Components
{
    struct Transform : public Component
    {
        Transform(Game::Entity* entity, Vector2 position, float scale, float rotation) : position(position), scale(scale), rotation(rotation), Component(entity) {}

        Transform(Game::Entity* entity) : Transform(entity, Vector2(0, 0), 1.0f, 0) {}
        // TODO: Very inefficient way to store position, scale and rotation
        // but it's so convenient ...
        Vector2 position;
        float scale;
        float rotation;
    };
}

#endif //TRANSFORM_H
