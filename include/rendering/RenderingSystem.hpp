#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"
#include <vector>

namespace invalpha
{
    namespace engine2d
    {
        namespace rendering
        {
            class RenderingSystem
            {
            public:
                void initRenderingSystem()
                {

                }
            private:
                GLuint sprite_VAO = 0;
                std::vector<GLuint> sprites_to_render;
            };
        }
    }
}