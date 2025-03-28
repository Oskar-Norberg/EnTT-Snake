//
// Created by Oskar.Norberg on 2025-03-25.
//

#include "Components/Engine/SpriteRenderer.h"

#include <raylib.h>

namespace Components
{
    SpriteRenderer::SpriteRenderer(Game::Entity* entity) : Component(entity)
    {
        // TODO: Is there any way to get rid of this ass-path?
        texture_ = LoadTexture("../assets/builtin/textures/checkers.png");
    }

    void SpriteRenderer::Render(Transform transform) const
    {
        // TODO: Add support for non uniform scaling
        auto rectangle = Rectangle{transform.position.x, transform.position.y, transform.scale, transform.scale};
        DrawTexturePro(texture_, Rectangle{0,0, static_cast<float>(texture_.width), static_cast<float>(texture_.height)}, rectangle, Vector2{0,0},0, WHITE);
    }
}
