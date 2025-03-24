//
// Created by SkummisDenAndre on 2025-03-22.
//

#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

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
        
        virtual void Update(float deltaTime) {}
        virtual void OnCollision(Game::Entity* other) {}

        void SetEntity(Game::Entity* entity)
        {
            entity_ = entity;
        }
    private:
        Game::Entity* entity_;
    };
}

#endif //CUSTOMCOMPONENT_H
