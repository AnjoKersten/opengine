/*
Include libraries here
*/
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
Include classes here
*/
#include "src/Renderer/renderer.h"
#include "src/Renderer/shader.h"
#include "src/Model/model.h"
#include "src/Renderer/camera.h"
#include "src/Graphics/Light.h"
#include "src/UI/UICollection.h"
#include "src/UI/UIText.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main() {
    Renderer renderer;
    config con;

    Shader modelShader("../src/Shaders/model.vs", "../src/Shaders/model.fs");
    Model myModel("assets/Models/Bear/bear.obj");

    //temporary 
    Shader skyboxShader("../src/Shaders/skybox.vs", "../src/Shaders/skybox.fs");
    Shader cubemapShader("../src/Shaders/cubemap.vs", "../src/Shaders/cubemap.fs");

    renderer.setupSkybox(cubemapShader, skyboxShader);

    glfwSetFramebufferSizeCallback(renderer.window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
        camera.processInput(renderer.window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now
        camera.projection;
        camera.view;

        modelShader.use();
        camera.projection = glm::perspective(glm::radians(camera.Zoom), con.xRes / con.yRes, 0.1f, 100.0f);
        camera.view = camera.GetViewMatrix();
		modelShader.setMat4("projection", camera.projection);
		modelShader.setMat4("view", camera.view);

        // Draw the loaded model
    	glm::mat4 model;
    	model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
    	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
    	glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));

    	myModel.Draw(modelShader);

        camera.view = glm::mat4(glm::mat3(camera.GetViewMatrix()));
        renderer.drawSkybox(camera.projection, camera.view, skyboxShader);

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
