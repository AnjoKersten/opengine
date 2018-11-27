#include <glad.h>
#include <glfw3.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include "src/Texture/stb_image.h"
#include "src/Renderer/renderer.h"
#include "src/Renderer/shader.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    Renderer renderer;
	  Shader demoShader("../src/shaders/vertex.vs", "../src/shaders/fragment.fs");

    renderer.createRectangle();

    Texture tex("assets/wall.jpg");
    Texture secTex("assets/fire.jpg");

    demoShader.use();
    glUniform1i(glGetUniformLocation(demoShader.ID, "texture1"), 0);
    demoShader.setInt("texture2", 1);

    glfwSetFramebufferSizeCallback(renderer.window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
		    demoShader.use();

        glActiveTexture(GL_TEXTURE0);
    		glBindTexture(GL_TEXTURE_2D, tex.texID);
    		glActiveTexture(GL_TEXTURE1);
    		glBindTexture(GL_TEXTURE_2D, secTex.texID);

        //render here
		    renderer.drawRectangle();

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
