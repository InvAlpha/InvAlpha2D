#pragma once
#include "..//rendering/RenderingSystem.hpp"
#include "..//resource/ResourceSystem.hpp"
#include "..//gameobject/SpriteManager.hpp"
#include <memory>

namespace invalpha
{
    namespace engine2d
    {
        namespace application
        {
            class SystemManager
            {
            public:
                void initSystems(GLuint& window_width, GLuint& window_height)
                {
                    resources_ptr = std::make_shared<resource::ResourceSystem>();
                    sprites_ptr = std::make_shared<gameobject::SpriteManager>();
                    renderings_ptr = std::make_shared<rendering::RenderingSystem>();
                    renderings_ptr->initRenderingSystem(&window_width, &window_height, sprites_ptr, resources_ptr);
                }
                decltype(auto) getRenderingSPointer() const { return renderings_ptr; }
                decltype(auto) getResourceSPointer() const { return resources_ptr; }
                decltype(auto) getSpriteSPointer() const { return sprites_ptr; }
             private:
                std::shared_ptr<rendering::RenderingSystem> renderings_ptr;
                std::shared_ptr<resource::ResourceSystem> resources_ptr;
                std::shared_ptr<gameobject::SpriteManager> sprites_ptr;
            };
        }
    }
}