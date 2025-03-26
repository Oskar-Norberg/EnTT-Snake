//
// Created by Oskar.Norberg on 2025-03-25.
//

#ifndef MOVEONCOLLISION_H
#define MOVEONCOLLISION_H

#include "Entity.h"
#include "Components/CustomComponent/CustomComponent.h"
#include "Components/Engine/Transform.h"

class MoveOnCollision : public Components_Custom::CustomComponent
{
    void OnCollision(Game::Entity* entity) override
    {
        auto* transform = entity_->GetComponent<Components::Transform>();

        transform->position = Core_Utils::Vector2{(float) (rand() % 100) + 100, (float) (rand() % 100) + 100};
    }
};

#endif //MOVEONCOLLISION_H
