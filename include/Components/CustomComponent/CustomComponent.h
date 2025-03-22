//
// Created by SkummisDenAndre on 2025-03-22.
//

#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

#include "Components/Engine/Component.h"
#include "Entity.h"

namespace Components_Custom
{
    // TODO: This doesn't really have to inherit from Component. Remove to make room for custom API.
    struct CustomComponent : public Components::Component
    {
        CustomComponent(Game::Entity* entity) : Component(entity) {}

        virtual void OnCreation(){}
        virtual void OnDestroy(){}
        
        virtual void Update(float deltaTime) {}
        virtual void OnCollision(Game::Entity* other) {}
    };
}

#endif //CUSTOMCOMPONENT_H
