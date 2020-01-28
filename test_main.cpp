#include "dependencies/SDL2-2.0.10/include/SDL.h"
#pragma comment(lib, "dependencies/SDL2-2.0.10/lib/x86/SDL2.lib")
#pragma comment(lib, "dependencies/SDL2-2.0.10/lib/x86/SDL2main.lib")
#include "include/application/Application.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    invalpha::engine2d::application::Application app;
    app.setAppName("InvAlpha2D Test");
    app.loadResources("test.txt");
    auto pack = app.getManager()->getResourceSPointer()->fetchShaderPackPtr(0);
    app.getManager()->getSpriteSPointer()->createSprite(128, 128, 0, 0, true, 0, pack->fetchVertexShader(), pack->fetchFragmentShader(), 0.0f);
    app.startRenderingLoop();
    return 0;
}