#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "../config.h"
#include "../Graphics/skybox.h"
#include "shader.h"
#include "../UI/UIText.h"
#include "../UI/UICollection.h"
#include "../Texture/FontLoader.h"
#include "../Model/model.h"

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    void processInput(GLFWwindow* window);
    void init(Shader cubemapShader, Shader skyboxShader);
    void drawSkybox(glm::mat4 view, glm::mat4 projection, Shader skyboxShader);
    void renderText(UIText* text, UICollection* parent, Shader* shader);
    void renderOBJ(Model mod, glm::mat4 proj, glm::mat4 view, Shader modShader);
    // cleans up the VBO's, VAO's and the EBO's.
    void cleanUp();
    // view and projection matrices.
private:
    Skybox box;
    config con;
    unsigned int VBO, VAO, EBO;
    unsigned int skyboxVAO, skyboxVBO;
    vector<string> const faces {
        "assets/Sprites/Skybox/right.tga",
		"assets/Sprites/Skybox/left.tga",
		"assets/Sprites/Skybox/top.tga",
		"assets/Sprites/Skybox/bottom.tga",
		"assets/Sprites/Skybox/front.tga",
		"assets/Sprites/Skybox/back.tga"
    };
};

#endif
