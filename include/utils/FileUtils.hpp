#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>

namespace invalpha
{
    namespace engine2d
    {
        namespace utils
        {
            class FileUtils
            {
            public:
                static std::shared_ptr<FileUtils> getInstance()
                {
                    if (!instance)
                        instance = std::make_shared<FileUtils>();
                    return instance;
                }

                std::string loadWholeFile(const std::string &file_path)
                {
                    std::string result;
                    std::stringstream ssm;
                    std::ifstream fin(file_path);
                    if (!fin)
                    {
                        std::cout << "[FileUtils] Couldn't load file!" << std::endl;
                        return std::string();
                    }
                    ssm << fin.rdbuf();
                    result = ssm.str();
                    fin.close();
                    return result;
                }
            private:
                static std::shared_ptr<FileUtils> instance;
            };
        }
    }
}