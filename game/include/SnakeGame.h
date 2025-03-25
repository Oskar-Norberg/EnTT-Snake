//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Engine.h"

namespace Scenes
{
    class Scene;
}

namespace Snake
{

    class SnakeGame
    {
    public:
        SnakeGame();
        ~SnakeGame();
    
        void Run();
        
    private:
        Core::Engine engine_;

        Scenes::Scene* playing_scene_;
    };
}

#endif //SNAKEGAME_H
