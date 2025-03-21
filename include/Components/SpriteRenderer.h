//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "raylib.h"

namespace Components
{
    struct SpriteRenderer
    {
        SpriteRenderer()
        {
            texture_ = LoadTexture("resources/snake.png");
        }
        ~SpriteRenderer()
        {
            
        }
        
        Texture2D texture_;
    };
}

#endif //SPRITERENDERER_H
