#pragma once
#include "..//..//dependencies/stb-master/stb_image.h"
#include "..//utils/FileUtils.hpp"
#include "..//rendering/Texture2D.hpp"
#include "ShaderPack.hpp"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

namespace invalpha
{
    namespace engine2d
    {
        namespace resource
        {
            class ResourceSystem
            {
            public:
                void loadResourceList(const std::string& reslist_path)
                {
                    auto futils = utils::FileUtils::getInstance();
                    std::string res_list = futils->loadWholeFile(reslist_path);
                    std::string buffer;
                    std::istringstream issm(res_list);
                    while (issm)
                    {
                        issm >> buffer;

                    }
                }
                void loadShader(const std::string& vertex_shader_path,
                    const std::string& fragment_shader_path)
                {
                    auto fileutils_instance = utils::FileUtils::getInstance();
                    auto vshader_str = fileutils_instance->loadWholeFile(vertex_shader_path);
                    auto fshader_str = fileutils_instance->loadWholeFile(fragment_shader_path);
                    auto vshader_src = vshader_str.c_str();
                    auto fshader_src = fshader_str.c_str();

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

                    shaders.emplace_back(vshader_id, fshader_id);
                }
                void loadTexture(const std::string& img_path)
                {
                    GLuint texture = 0;
                    glGenTextures(1, &texture);
                    glBindTexture(GL_TEXTURE_2D, texture);
                    // set the texture wrapping parameters
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    // set texture filtering parameters
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    // load image, create texture and generate mipmaps
                    int width, height, nrChannels;
                    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
                    unsigned char* data = stbi_load(img_path.c_str(), &width, &height, &nrChannels, 0);
                    if (data)
                    {
                        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                        glGenerateMipmap(GL_TEXTURE_2D);
                    }
                    else
                    {
                        std::cout << "[ResourceManager] Failed to load texture" << std::endl;
                    }
                    stbi_image_free(data);

                    textures.emplace_back(texture);
                }
                // Warning: no index check!!
                ShaderPack* fetchShaderPackPtr(const GLuint& id) { return &shaders[id]; }
                rendering::Texture2D* fetchTexturePtr(const GLuint& id) { return &textures[id]; }
            private:
                std::vector<ShaderPack> shaders;
                std::vector<rendering::Texture2D> textures;
            };
        }
    }
}