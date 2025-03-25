//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

#include "Vector2.h"

namespace Components
{
    struct Transform : public Component
    {
        Transform(Game::Entity* entity, Core_Utils::Vector2 position, float scale, float rotation) : position(position), scale(scale), rotation(rotation), Component(entity) {}
        Transform(Game::Entity* entity, Core_Utils::Vector2 position, float scale) : Transform(entity, position, scale, 0) {}
        Transform(Game::Entity* entity, float scale) : Transform(entity, Core_Utils::Vector2(0, 0), scale, 0) {}
        Transform(Game::Entity* entity) : Transform(entity, Core_Utils::Vector2(0, 0), 1.0f, 0) {}
        // TODO: Very inefficient way to store position, scale and rotation
        // but it's so convenient ...
        Core_Utils::Vector2 position;
        float scale;
        float rotation;
    };
}

#endif //TRANSFORM_H
