#pragma once
#include "..//utils/FileUtils.hpp"
#include "..//rendering/Shader.hpp"
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
            private:
                std::vector<rendering::Shader> shaders;
            };
        }
    }
}