#pragma once
#include "..//rendering/RenderingSystem.hpp"
#include "..//resource/ResourceSystem.hpp"
#include "..//rendering/SpriteManager.hpp"
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
                void initSystems()
                {
                    renderings_ptr = std::make_shared<rendering::RenderingSystem>();
                    resources_ptr = std::make_shared<resource::ResourceSystem>();
                    sprites_ptr = std::make_shared<rendering::SpriteManager>();
                }
                decltype(auto) getRenderingSPointer() const { return renderings_ptr; }
                decltype(auto) getResourceSPointer() const { return resources_ptr; }
                decltype(auto) getSpriteSPointer() const { return sprites_ptr; }
             private:
                std::shared_ptr<rendering::RenderingSystem> renderings_ptr;
                std::shared_ptr<resource::ResourceSystem> resources_ptr;
                std::shared_ptr<rendering::SpriteManager> sprites_ptr;
            };
        }
    }
}