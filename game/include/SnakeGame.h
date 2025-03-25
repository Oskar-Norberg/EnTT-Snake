//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <vector>

#include "SceneManager.h"

namespace Snake
{

    class SnakeGame
    {
    public:
        SnakeGame();
        ~SnakeGame();
    
        void Run();
        
    private:
        std::vector<Scenes::Scene*> states_;
        Scenes::SceneManager sceneManager_;
    };
}

#endif //SNAKEGAME_H
