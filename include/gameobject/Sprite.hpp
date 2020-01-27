#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"
#include "../rendering/Shader.hpp"
#include "..//..//dependencies/glm/glm/vec3.hpp"

namespace invalpha
{
    namespace engine2d
    {
        namespace gameobject
        {
            class Sprite
            {
            public:
                Sprite(const GLuint& id_, const GLuint& component_id_, const GLuint& texture_id_,
                    const GLuint& pos_x_, const GLuint& pos_y_, const GLuint& width_,
                    const GLuint& height_, const GLfloat& rotate_, const GLuint& vshader_id, const GLuint& fshader_id,
                    const glm::vec3& color_):
                    id(id_), component_id(component_id_), pos_x(pos_x_), pos_y(pos_y_), width(width_), height(height_),
                    rotate(rotate_), shader(vshader_id, fshader_id), color(color_) {}
                GLuint id = 0;
                GLuint component_id = 0;
                GLuint pos_x = 0;
                GLuint pos_y = 0;
                GLuint width = 0;
                GLuint height = 0;
                // Don't confuse this with the same variable of Texture2D!! 
                // This variable is used to fetch Texture2D object from the ResourceManager
                GLuint texture_id = 0;
                GLfloat rotate = 0;
                glm::vec3 color;
                rendering::Shader shader;
            };
        }
    }
}