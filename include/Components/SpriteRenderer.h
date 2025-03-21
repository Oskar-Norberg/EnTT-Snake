//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "raylib.h"
#include "Transform.h"

namespace Components
{
    struct SpriteRenderer
    {
        SpriteRenderer()
        {
            // TODO: Is there any way to get rid of this ass-path?
            texture_ = LoadTexture("../assets/builtin/textures/checkers.png");
        }
        ~SpriteRenderer()
        {
            
        }

        void Render(Transform transform)
        {
            DrawTextureEx(texture_, transform.position, transform.rotation, transform.scale, WHITE);
        }
        
        Texture2D texture_;
    };
}

#endif //SPRITERENDERER_H
