//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include <vector>

#include "raylib.h"
#include "Components/Component.h"

namespace Components{
    struct BoxCollider : public Component
    {
        explicit BoxCollider(Game::Entity* entity, Rectangle rectangle) : collider(rectangle), Component(entity) {}
        Rectangle collider;

        // TODO: this function is going to be the slowest thing ever
        // TODO: It shouldn't really be here either? Maybe in a physics class?
        std::vector<BoxCollider> CheckForCollisions(const std::vector<BoxCollider>& boxColliders) const
        {
            std::vector<BoxCollider> collidedWith = {};
            
            for (auto& other : boxColliders)
            {
                // Skip self
                if (&other.collider == &collider)
                    continue;
                
                if (CheckCollisionRecs(collider, other.collider))
                    collidedWith.push_back(other);
            }
            
            return collidedWith;
        }
    };
}

#endif //BOXCOLLIDER_H
