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

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    void processInput(GLFWwindow* window);
    void setupSkybox(Shader cubemapShader, Shader skyboxShader);
    void drawSkybox(glm::mat4 view, glm::mat4 projection, vector<string> faces, Shader skyboxShader);
    // cleans up the VBO's, VAO's and the EBO's.
    void cleanUp();
    // view and projection matrices.
private:
    Skybox box;
    config con;
    unsigned int VBO, VAO, EBO;
    unsigned int skyboxVAO, skyboxVBO;
};

#endif
