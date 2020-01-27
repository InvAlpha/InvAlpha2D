#pragma once
#include "..//..//dependencies/glad/include/glad/glad.h"
#include "..//..//dependencies/glm/glm/ext/matrix_double2x2.hpp"
#include "..//..//dependencies/glm/glm/gtc/type_ptr.hpp"
#include "..//gameobject/ComponentDefs.hpp"
#include "..//resource/ResourceSystem.hpp"
#include "../gameobject/SpriteManager.hpp"
#include <memory>
#include <iostream>

namespace invalpha
{
    namespace engine2d
    {
        namespace rendering
        {
            class RenderingSystem
            {
            public:
                void initRenderingSystem(GLuint* pWindowWidth, GLuint* pWindowHeight,
                    const std::shared_ptr<gameobject::SpriteManager> &pSpriteManager,
                    const std::shared_ptr<resource::ResourceSystem> &pResManager)
                {
                    pointer_sprite_manager = pSpriteManager;
                    width = pWindowWidth;
                    height = pWindowHeight;

                    GLuint sprite_VBO = 0;
                    glGenVertexArrays(1, &sprite_VAO);
                    glGenBuffers(1, &sprite_VBO);
                    GLfloat vertices[] = {
                        0.0f, 1.0f, 0.0f, 1.0f,
                        1.0f, 0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 0.0f, 0.0f,

                        0.0f, 1.0f, 0.0f, 1.0f,
                        1.0f, 1.0f, 1.0f, 1.0f,
                        1.0f, 0.0f, 1.0f, 0.0f
                    };
                    glBindBuffer(GL_ARRAY_BUFFER, sprite_VBO);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
                    glBindVertexArray(sprite_VAO);
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
                    glBindBuffer(GL_ARRAY_BUFFER, 0);
                    glBindVertexArray(0);

                    projection=glm::ortho(0.0f, (GLfloat)(*width),
                        (GLfloat)(*height), 0.0f, -1.0f, 1.0f);
                }
                void drawSprite(gameobject::Sprite &sprite)
                {
                    sprite.shader.useProgram();
                    glm::mat4 model;
                    model = glm::translate(model, glm::vec3(sprite.pos_x, sprite.pos_y, 0.0f));

                    model = glm::translate(model, glm::vec3(0.5f * (GLfloat)sprite.width, 0.5f * (GLfloat)sprite.height, 0.0f));
                    model = glm::rotate(model, sprite.rotate, glm::vec3(0.0f, 0.0f, 1.0f));
                    model = glm::translate(model, glm::vec3(-0.5f * (GLfloat)sprite.width, -0.5f * (GLfloat)sprite.height, 0.0f));

                    model = glm::scale(model, glm::vec3((GLfloat)sprite.width, (GLfloat)sprite.height, 1.0f));

                    sprite.shader.setMatrix4f("model", model);
                    sprite.shader.setVector3f("color", sprite.color);

                    glActiveTexture(GL_TEXTURE0);
                    pointer_res_manager->fetchTexturePtr(sprite.texture_id)->bindTexture();

                    glBindVertexArray(sprite_VAO);
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                    glBindVertexArray(0);
                }
                void drawSprites()
                {
                    gameobject::Sprite* sprite_ptr = nullptr;
                    for (auto i = pointer_sprite_manager->getSpriteNum(); i != 0; i--)
                    {
                        sprite_ptr = pointer_sprite_manager->getSpriteByID(i);
                        if (sprite_ptr->component_id & gameobject::COMPONENT_RENDERING)
                        {
                            drawSprite(*sprite_ptr);
                        }
                    }
                }
            private:
                GLuint sprite_VAO = 0;
                glm::mat4 projection;

                std::shared_ptr<gameobject::SpriteManager> pointer_sprite_manager;
                std::shared_ptr<resource::ResourceSystem> pointer_res_manager;
                GLuint* width = nullptr;
                GLuint* height = nullptr;
            };
        }
    }
}