#pragma once
#include "Sprite.hpp"
#include <vector>
#include <string>

namespace invalpha
{
    namespace engine2d
    {
        namespace rendering
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
                    
                }
            private:
                std::vector<Sprite> sprite_storage;
            };
        }
    }
}