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
            DrawTexturePro(texture_, Rectangle{0,0, static_cast<float>(texture_.width),static_cast<float>(texture_.height)}, rectangle, Vector2{0,0},0, WHITE);
            // DrawTextureRec(texture_, rectangle, transform.position, WHITE);
        }
        
        Texture2D texture_;
    };
}

#endif //SPRITERENDERER_H
