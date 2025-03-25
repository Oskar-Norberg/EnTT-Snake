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
        std::function<void()> OnCreate;
        std::function<void()> OnDestroy;
        std::function<void(float deltaTime)> OnUpdate;

        // TODO: Find a way to pass the game entity wrapper instead of the entt entity
        std::function<void(entt::entity other)> OnCollision;
        
        explicit ScriptableComponent(Game::Entity* entity) : Component(entity), component_(nullptr)
        {
        }

        ~ScriptableComponent() = default;

        template<typename T>
        void Bind()
        {
            OnCreate = [this](){component_ = new T(); component_->SetEntity(entity_); component_->OnCreation();};
            OnDestroy = [this](){component_->OnDestroy(); delete component_;};

            OnUpdate = [this](float deltaTime){component_->OnUpdate(deltaTime);};
            OnCollision = [this](entt::entity other){component_->OnCollision(other);};
        }

        bool IsInstantiated() const
        {
            return component_ != nullptr;
        }

    private:
        Components_Custom::CustomComponent* component_;
    };
}

#endif //SCRIPTABLECOMPONENT_H
