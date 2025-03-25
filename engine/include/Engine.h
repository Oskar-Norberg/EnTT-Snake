//
// Created by Oskar.Norberg on 2025-03-25.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "SceneManager.h"

namespace Core{
    class Engine{
    public:
        Engine();
        ~Engine();

        void SetScene(Scenes::Scene* scene);

        void Run();
        void Stop();
        
    private:
        Scenes::SceneManager sceneManager_;
    };
}

#endif //ENGINE_H
