#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"
#include "../../dependencies/SDL2-2.0.10/include/SDL.h"
#include "SystemManager.hpp"
#include <string>
#include <iostream>

namespace invalpha
{
    namespace engine2d
    {
        namespace application
        {
            class Application
            {
            public:
                Application()
                {
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
                    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
                    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                    SDL_Init(SDL_INIT_EVERYTHING);

                    window_ptr = SDL_CreateWindow(app_name.c_str(), 800, 450, window_width, window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
                    gl_context = SDL_GL_CreateContext(window_ptr);
                    SDL_GL_SetSwapInterval(1);

                    gladLoadGL();
                    glViewport(0, 0, window_width, window_height);

                    smanager.initSystems(window_width, window_height);
                }
                void setAppName(const std::string& name)
                {
                    if (!name.empty())
                    {
                        app_name = name;
                        SDL_SetWindowTitle(window_ptr, name.c_str());
                    }
                    else
                        std::cout << "[Application] Invalid App Name!" << std::endl;
                }
                void setAppSize(const std::size_t& width, const std::size_t& height)
                {
                    if (width == 0 || height == 0)
                        std::cout << "[Application] Invalid Window Size!" << std::endl;
                    else
                    {
                        window_width = width;
                        window_height = height;
                        SDL_SetWindowSize(window_ptr, static_cast<int>(window_width), static_cast<int>(window_height));
                    }
                }
                void startRenderingLoop()
                {
                    while (!window_should_close)
                    {

                        SDL_GL_SwapWindow(window_ptr);
                    }
                }
                ~Application()
                {
                    SDL_DestroyWindow(window_ptr);
                    window_ptr = nullptr;
                    gl_context = nullptr;
                    SDL_Quit();
                }
            private:
                std::string app_name;
                GLuint window_width = 800;
                GLuint window_height = 600;
                SDL_Window* window_ptr = nullptr;
                SDL_GLContext gl_context = nullptr;
                bool window_should_close = false;
                SDL_Event event;

                SystemManager smanager;
            };
        }
    }
}