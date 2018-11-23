#ifndef RENDERER_H
#define RENDERER_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>

class Renderer
{
public:
    Renderer();
    virtual ~Renderer();
    GLFWwindow* window;
    
    void processInput(GLFWwindow* window);
    void loadShader();
    void makeTriangle();
    void cleanUp();
    
    unsigned int vertexShader;
    unsigned int fragmentShader;
    
private:
    int _WIDTH = 800;
    int _HEIGHT = 600;
    
    const char *vertexShaderSource;
    const char *fragmentShaderSource;
    
    unsigned int shaderProgram;
    
    unsigned int VBO, VAO, EBO;
};

#endif
