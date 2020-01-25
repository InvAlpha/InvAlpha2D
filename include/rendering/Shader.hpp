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
                void loadShader(const std::string& vertex_shader_path,
                    const std::string& fragment_shader_path)
                {
                    auto fileutils_instance = utils::FileUtils::getInstance();
                    auto vshader_str = fileutils_instance->loadWholeFile(vertex_shader_path);
                    auto fshader_str = fileutils_instance->loadWholeFile(fragment_shader_path);
                    auto vshader_src = vshader_str.c_str();
                    auto fshader_src = fshader_str.c_str();

                    program_id = glCreateProgram();
                    auto vshader_id = glCreateShader(GL_VERTEX_SHADER);
                    auto fshader_id = glCreateShader(GL_FRAGMENT_SHADER);
                    int success = 0;
                    char info[512];

                    glShaderSource(vshader_id, 1, &vshader_src, nullptr);
                    glCompileShader(vshader_id);
                    glGetShaderiv(vshader_id, GL_COMPILE_STATUS, &success);
                    if (!success)
                    {
                        glGetShaderInfoLog(vshader_id, 512, nullptr, info);
                        std::cout << "[Shader] Failed to compile the vertex shader from " <<
                            vertex_shader_path << std::endl;
                        std::cout << "ERROR info: " << info << std::endl;
                        return;
                    }

                    glShaderSource(fshader_id, 1, &fshader_src, nullptr);
                    glCompileShader(fshader_id);
                    glGetShaderiv(fshader_id, GL_COMPILE_STATUS, &success);
                    if (!success)
                    {
                        glGetShaderInfoLog(fshader_id, 512, nullptr, info);
                        std::cout << "[Shader] Failed to compile the fragment shader from " <<
                            fragment_shader_path << std::endl;
                        std::cout << "ERROR info: " << info << std::endl;
                        return;
                    }

                    glAttachShader(program_id, vshader_id);
                    glAttachShader(program_id, fshader_id);
                    glLinkProgram(program_id);
                    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
                    if (!success)
                    {
                        glGetProgramInfoLog(program_id, 512, nullptr, info);
                        std::cout << "[Shader] Failed to link the program sourced from these shaders" <<
                            vertex_shader_path << " and " << fragment_shader_path << std::endl;
                        std::cout << "ERROR info: " << info << std::endl;
                        return;
                    }

                    glDeleteShader(vshader_id);
                    glDeleteShader(fshader_id);
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