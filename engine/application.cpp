#include <glad.h>
#include <glfw3.h>

#include <src/shader.h>

#include <src/renderer.h>

int main()
{
    Renderer renderer;
    
    Shader shader("../src/shaders/SimpleVertexShader.vs", "../src/shaders/SimpleFragmentShader.fs");
    
    renderer.CreateTriangle();
    
    // render loop
    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
        
        shader.use();
        renderer.DrawTriangle();
        
        glfwSwapBuffers(renderer.window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
