#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../config.h"
#include "../Graphics/skybox.h"

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    void processInput(GLFWwindow* window);
    void DrawSkybox();
    void cleanUp();
private:
    unsigned int VBO, VAO, EBO;
};

#endif
