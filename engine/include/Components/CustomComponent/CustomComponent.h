//
// Created by SkummisDenAndre on 2025-03-22.
//

#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

#include <iostream>

namespace Game
{
    class Entity;
}

namespace Components_Custom
{
    struct CustomComponent
    {
        CustomComponent() = default;

        virtual void OnCreation(){}
        virtual void OnDestroy(){}
        
        virtual void OnUpdate(float deltaTime) {}
        
        virtual void OnCollision(entt::entity other) {}

        void SetEntity(Game::Entity* entity)
        {
            entity_ = entity;
        }
    protected:
        Game::Entity* entity_;
    };
}

#endif //CUSTOMCOMPONENT_H
