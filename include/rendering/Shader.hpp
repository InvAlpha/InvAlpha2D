#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"
#include "..//utils/FileUtils.hpp"
#include "..//..//dependencies/glm/glm/ext/matrix_double2x2.hpp"
#include "..//..//dependencies/glm/glm/gtc/type_ptr.hpp"

#include <string>

namespace invalpha
{
    namespace engine2d
    {
        namespace rendering
        {
            class Shader
            {
            public:
                Shader(const GLuint& vshader_id,
                    const GLuint& fshader_id)
                {
                    program_id = glCreateProgram();
                    int success = 0;
                    char info[512];
                    glAttachShader(program_id, vshader_id);
                    glAttachShader(program_id, fshader_id);
                    glLinkProgram(program_id);
                    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
                    if (!success)
                    {
                        glGetProgramInfoLog(program_id, 512, nullptr, info);
                        std::cout << "[Shader] Failed to link the program sourced from these shaders" <<
                            vshader_id << " and " << fshader_id << std::endl;
                        std::cout << "ERROR info: " << info << std::endl;
                        return;
                    }
                }
                void useProgram() const
                {
                    glUseProgram(program_id);
                }
                void setBool(const std::string& name, const bool &value) const
                {
                    glUniform1i(glGetUniformLocation(program_id, name.c_str()), (int)value);
                }
                void setInt(const std::string& name, const int &value) const
                {
                    glUniform1i(glGetUniformLocation(program_id, name.c_str()), value);
                }
                void setFloat(const std::string& name, const float &value) const
                {
                    glUniform1f(glGetUniformLocation(program_id, name.c_str()), value);
                }
                void setMatrix4f(const std::string& name, const glm::mat4& matrix4f)
                {
                    glUniformMatrix4fv(glGetUniformLocation(program_id, name.c_str()), 1, true, glm::value_ptr(matrix4f));
                }
                void setVector3f(const std::string& name, const glm::vec3& vector3f)
                {
                    glUniform3f(glGetUniformLocation(program_id, name.c_str()), vector3f.x, vector3f.y, vector3f.z);
                }
            private:
                unsigned int program_id = 0;
            };
        }
    }
}