#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"

namespace invalpha
{
    namespace engine2d
    {
        namespace rendering
        {
            class Sprite
            {
            public:
                GLuint getSpriteWidth() const { return width; }
                GLuint getSpriteHeight() const { return height; }
                GLuint getSpriteID() const { return id; }
                GLuint getSpriteComponentID() const { return component_id; }
                GLuint getSpriteTextureID() const { return texture_id; }
                GLuint getShaderID() const { return shader_id; }
                GLuint getSpritePosX() const { return pos_x; }
                GLuint getSpritePoxYy() const { return pos_y; }
            protected:
                GLuint id = 0;
                GLuint component_id = 0;
                GLuint pos_x = 0;
                GLuint pos_y = 0;
                GLuint width = 0;
                GLuint height = 0;
                GLuint texture_id = 0;
                GLuint shader_id = 0;
            };
        }
    }
}