#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>

#include "src/shader.h"
#include "src/texture.h"

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    void processInput(GLFWwindow* window);
    void createRectangle();
    void drawRectangle();
    void cleanUp();
private:
    //Width and height for screen resolution
    int _WIDTH = 800;
    int _HEIGHT = 600;

    const char *vertexShaderSource;
    const char *fragmentShaderSource;

    unsigned int shaderProgram;
    unsigned int VBO, VAO, EBO;
};

#endif
