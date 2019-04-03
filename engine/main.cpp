/*
Include libraries here
*/
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
Include classes here
*/
#include <glfw3.h>
#include "src/Renderer/renderer.h"
#include "src/Renderer/shader.h"
#include "src/Model/model.h"
#include "src/Renderer/camera.h"
#include "src/Core/core.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
	
    Camera* camera = new Camera(glm::vec3(0.0f, -1.5f, 2.5f));
    config con;
    Core core;
    Renderer renderer;

    Shader modelShader("../src/Shaders/model.vs", "../src/Shaders/model.fs");
    Model myModel("assets/Models/Bear/bear.obj");

    Shader skyboxShader("../src/Shaders/skybox.vs", "../src/Shaders/skybox.fs");

    glfwSetFramebufferSizeCallback(core.window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(core.window)) {
	renderer.processInput(core.window);
        camera->processInput(core.window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now

        camera->projection = glm::perspective(glm::radians(camera->Zoom), con.xRes / con.yRes, 0.1f, 100.0f);
        camera->view = camera->GetViewMatrix();

        renderer.renderOBJ(myModel, camera->projection, camera->view, modelShader);

        camera->view = glm::mat4(glm::mat3(camera->GetViewMatrix()));
        renderer.drawSkybox(camera->projection, camera->view, skyboxShader);

        glfwSwapBuffers(core.window);
        glfwPollEvents();
    }
    renderer.cleanUp();
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
