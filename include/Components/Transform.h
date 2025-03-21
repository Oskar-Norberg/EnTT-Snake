//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "raylib.h"

namespace Component
{
    struct Transform
    {
        Transform() : position({0, 0}), scale(1.0f), rotation(0.0f) {}
        Transform(Vector2 position, float scale, float rotation) : position(position), scale(scale), rotation(rotation) {}
        // TODO: Very inefficient way to store position, scale and rotation
        // but it's so convenient ...
        Vector2 position;
        float scale;
        float rotation;
    };
}

#endif //TRANSFORM_H
