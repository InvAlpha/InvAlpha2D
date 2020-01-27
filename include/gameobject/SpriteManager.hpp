#pragma once
#include "Sprite.hpp"
#include <vector>
#include <string>

namespace invalpha
{
    namespace engine2d
    {
        namespace gameobject
        {
            class SpriteManager
            {
            public:
                void createSprite(const GLuint& width,
                    const GLuint& height,
                    const GLuint& pos_x,
                    const GLuint& pos_y,
                    const bool& visibility,
                    const GLuint& texture_id,
                    const GLuint& shader_id
                    )
                {
                    sprite_storage.emplace_back();
                }
                // Warning: no index check!!
                Sprite* getSpriteByID(const GLuint& id) { return &sprite_storage[id]; }

                std::size_t getSpriteNum() const { return sprite_storage.size(); }
            private:
                std::vector<Sprite> sprite_storage;
            };
        }
    }
}