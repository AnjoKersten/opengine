#include <glad.h>
#include <glfw3.h>

#include "src/renderer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    Renderer renderer;
    
    glfwSetFramebufferSizeCallback(renderer.window, framebuffer_size_callback);
    
    // render loop
    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        renderer.loadShader();
        
        //render here
        renderer.makeTriangle();
        
        glfwSwapBuffers(renderer.window);
        glfwPollEvents();
    }
    
    renderer.cleanUp();
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
