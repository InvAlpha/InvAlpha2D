#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"

namespace invalpha
{
    namespace engine2d
    {
        namespace rendering
        {
            class Texture2D
            {
            public:
                Texture2D(const GLuint& texture_id_) :texture_id(texture_id_) {}
                void bindTexture() { glBindTexture(GL_TEXTURE_2D, texture_id); }
            private:
                GLuint texture_id = 0;
            };
        }
    }
}