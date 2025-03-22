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
        CustomComponent(Game::Entity* entity) {}

        virtual void OnCreation(){}
        virtual void OnDestroy(){}
        
        virtual void OnUpdate(float deltaTime) {}
        virtual void OnCollision(Game::Entity* other) {}

        template<typename T>
        T& GetComponent()
        {
            return entity->GetComponent<T>();
        }
    private:
        Game::Entity* entity;
    };
}

#endif //CUSTOMCOMPONENT_H
