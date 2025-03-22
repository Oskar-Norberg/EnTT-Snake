//
// Created by SkummisDenAndre on 2025-03-22.
//

#ifndef SCRIPTABLECOMPONENT_H
#define SCRIPTABLECOMPONENT_H

#include "Component.h"
#include "Components/CustomComponent/CustomComponent.h"

namespace Game
{
    class Entity;
}

namespace Components
{
    struct ScriptableComponent : public Component
    {
        std::function<void()> InstantiationFunction;
        std::function<void()> DestroyFunction;

        std::function<void()> OnCreateFunction;
        std::function<void()> OnDestroyFunction;
        std::function<void()> UpdateFunction;
        std::function<void()> OnCollisionFunction;
        
        ScriptableComponent(Game::Entity* entity) : Component(entity)
        {
        }

        ~ScriptableComponent()
        {
        }

        template<typename T>
        void Bind()
        {
            InstantiationFunction = [this](){component_ = new T();};
            DestroyFunction = [this](){delete component_;};

            OnCreateFunction = [this](){component_->OnCreation();};
            OnDestroyFunction = [this](){component_->OnDestroy();};

            // TODO: this shit doesnt work and idk why
            // UpdateFunction = [this](float deltaTime){component_->Update(deltaTime);};
            // OnCollisionFunction = [this](Game::Entity* other){component_->OnCollision(other);};
        }

    private:
        Components_Custom::CustomComponent* component_;
    };
}

#endif //SCRIPTABLECOMPONENT_H
