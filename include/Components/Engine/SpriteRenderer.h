//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "raylib.h"
#include "Transform.h"

namespace Components
{
    struct SpriteRenderer : public Component
    {
        SpriteRenderer(Game::Entity* entity) : Component(entity)
        {
            // TODO: Is there any way to get rid of this ass-path?
            texture_ = LoadTexture("../assets/builtin/textures/checkers.png");
        }
        
        ~SpriteRenderer()
        {
            
        }

        void Render(Transform transform)
        {
            // TODO: Add support for non uniform scaling
            Rectangle rectangle = Rectangle{transform.position.x, transform.position.y, transform.scale, transform.scale};
            DrawTextureRec(texture_, rectangle, transform.position, WHITE);
        }
        
        Texture2D texture_;
    };
}

#endif //SPRITERENDERER_H
