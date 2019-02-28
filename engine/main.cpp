/*
Include libraries here
*/
#include <glad.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
Include classes here
*/
#include "src/Renderer/renderer.h"
#include "src/Renderer/shader.h"
#include "src/Renderer/camera.h"
#include "src/Model/model.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main() {
    Renderer renderer;
    config con;

    Shader demoShader("../src/shaders/modelVertex.vs", "../src/shaders/modelFrag.fs");
    Model myModel("assets/Models/Bear/bear.obj");

    demoShader.use();

    glfwSetFramebufferSizeCallback(renderer.window, framebuffer_size_callback);

    glfwSetFramebufferSizeCallback(renderer.window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
        camera.processInput(renderer.window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        demoShader.use();
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), con.xRes / con.yRes, 0.1f, 100.0f);
		    glm::mat4 view = camera.GetViewMatrix();
		    demoShader.setMat4("projection", projection);
		    demoShader.setMat4("view", view);

        // Draw the loaded model
    		glm::mat4 model;
    		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
    		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
    		glUniformMatrix4fv(glGetUniformLocation(demoShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    		myModel.Draw(demoShader);

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
