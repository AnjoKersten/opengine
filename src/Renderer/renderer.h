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

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    void processInput(GLFWwindow* window);
    void setupSkybox(Shader cubemapShader, Shader skyboxShader);
    void drawSkybox(glm::mat4 view, glm::mat4 projection, Shader skyboxShader);
    void renderText(UIText* text, UICollection* parent, Shader* shader);
    // cleans up the VBO's, VAO's and the EBO's.
    void cleanUp();
    // view and projection matrices.
private:
    Skybox box;
    config con;
    unsigned int VBO, VAO, EBO;
    unsigned int skyboxVAO, skyboxVBO;
    FontLoader* fLoader;
    //All the faces for the skybox
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
