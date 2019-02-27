#include <glad.h>
#include <glfw3.h>
#include <iostream>

#include "src/Renderer/shader.h"
#include "src/Renderer/camera.h"
#include "src/Renderer/renderer.h"
#include "src/Model/model.h"
#include "src/config.h"

using namespace glm;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Camera camera(glm::vec3(0.0f, -0.2f, 3.0f));
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main() {
    Renderer renderer;
    config con;

    Shader modelShader("../src/shaders/modelVertex.vs", "../src/shaders/modelFrag.fs");
    Model myModel("assets/Bear/bear.obj");

    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
        camera.processInput(renderer.window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        modelShader.use();
        modelShader.setVec3("light.position", lightPos);
		    modelShader.setVec3("viewPos", camera.Position);

        modelShader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
			  modelShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
			  modelShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

        modelShader.setFloat("material.shininess", 8.0f);
        // view/projection transformations
        glm::mat4 projection = glm::perspective(camera.Zoom, con.xRes / con.yRes, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        modelShader.setMat4("projection", projection);
        modelShader.setMat4("view", view);

        // Draw the loaded model
        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
        modelShader.setMat4("model", model);

        myModel.Draw(modelShader);

        glfwSwapBuffers(renderer.window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
