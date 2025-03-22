//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <vector>
#include "StateMachine.h"

namespace Snake
{
    class SnakeGame
    {
    public:
        SnakeGame();
        ~SnakeGame();
    
        void Run();
        
    private:
        std::vector<States::State*> states_;
        States::StateMachine stateMachine_;
    };
}

#endif //SNAKEGAME_H
