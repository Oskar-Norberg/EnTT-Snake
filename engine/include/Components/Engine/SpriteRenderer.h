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
        SpriteRenderer(Game::Entity* entity);

        void Render(Transform transform) const;
        
        Texture2D texture_;
    };
}

#endif //SPRITERENDERER_H
