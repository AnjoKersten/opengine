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
    
    void CreateTriangle();
    void DrawTriangle();
    
private:
    int _WIDTH = 800;
    int _HEIGHT = 600;
    
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    
    unsigned int VBO, VAO;
};

#endif
