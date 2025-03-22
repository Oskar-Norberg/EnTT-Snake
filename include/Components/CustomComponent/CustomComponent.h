//
// Created by SkummisDenAndre on 2025-03-22.
//

#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

#include "Components/Engine/Component.h"
#include "Entity.h"

namespace Components_Custom
{
    struct CustomComponent : public Components::Component
    {
        CustomComponent(Game::Entity* entity) : Component(entity) {}

        virtual void Update() {}
        virtual void OnCollision(Game::Entity* other) {}
    };
}

#endif //CUSTOMCOMPONENT_H
