#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"
#include <utility>

namespace invalpha
{
    namespace engine2d
    {
        namespace resource
        {
            class ShaderPack
            {
            public:
                ShaderPack(const GLuint& vshader_id,const GLuint& fshader_id):
                    compiled_shaders(vshader_id, fshader_id) {}
                GLuint fetchVertexShader() const { return compiled_shaders.first; }
                GLuint fetchFragmentShader() const { return compiled_shaders.second; }
            private:
                std::pair<GLuint, GLuint> compiled_shaders;
            };
        }
    }
}