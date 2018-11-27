#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>

#include "src/Renderer/shader.h"
#include "src/Texture/texture.h"

class Camera;

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    void processInput(GLFWwindow* window);
    void finishRender(GLFWwindow& window, const Camera& camera);
    void renderQuads(const Camera& camera);
    void createRectangle();
    void drawRectangle();
    void cleanUp();
private:
    const char *vertexShaderSource;
    const char *fragmentShaderSource;
    unsigned int shaderProgram;
    unsigned int VBO, VAO, EBO;
};

#endif
