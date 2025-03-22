//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef COMPONENT_H
#define COMPONENT_H

namespace Game
{
    class Entity;
}

namespace Components
{
    struct Component
    {
    public:
        Component(Game::Entity* entity) : entity_(entity) {}
    protected:
        Game::Entity* entity_;
    };
}

#endif //COMPONENT_H
