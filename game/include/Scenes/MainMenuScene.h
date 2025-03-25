//
// Created by Oskar.Norberg on 2025-03-13.
//

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "Scene.h"

namespace Scenes
{
    class MainMenuScene : public Scene
    {
    public:
        MainMenuScene();
    
        void Enter(SceneManager* state_machine_) override;
        void Tick(SceneManager* state_machine_) override;
        void Exit(SceneManager* state_machine_) override;
    };
}

#endif //MAINMENUSTATE_H
