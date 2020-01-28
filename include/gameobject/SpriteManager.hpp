#pragma once
#include "Sprite.hpp"
#include "..//gameobject/ComponentDefs.hpp"
#include "..//rendering/Texture2D.hpp"
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
                    const GLuint& vshader_id,
                    const GLuint& fshader_id,
                    const GLfloat& rotate
                    )
                {
                    GLuint com_id = 0;
                    if (visibility)
                        com_id = gameobject::COMPONENT_RENDERING;
                    else
                        com_id = 0;
                    sprite_storage.emplace_back(sprite_max_index, com_id, texture_id, pos_x, pos_y, width, height, rotate, vshader_id, fshader_id);
                    ++sprite_max_index;
                }
                // Warning: no index check!!
                Sprite* getSpriteByID(const GLuint& id) { return &sprite_storage[id]; }

                std::size_t getSpriteNum() const { return sprite_storage.size(); }
                std::size_t getSpriteMaxIndex() const { return sprite_max_index; }
            private:
                std::vector<Sprite> sprite_storage;
                GLuint sprite_max_index = 0;
            };
        }
    }
}