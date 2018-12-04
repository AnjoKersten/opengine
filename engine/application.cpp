#include <glad.h>
#include <glfw3.h>
#include "src/Texture/stb_image.h"
#include "src/Renderer/renderer.h"
#include "src/Renderer/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../src/config.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

using namespace glm;

int main() {
    Renderer renderer;
    config con;
    glm::vec3 cubePositions[] = {
      glm::vec3( 0.0f,  0.0f,  0.0f),
      glm::vec3( 2.0f,  5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f),
      glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3( 2.4f, -0.4f, -3.5f),
      glm::vec3(-1.7f,  3.0f, -7.5f),
      glm::vec3( 1.3f, -2.0f, -2.5f),
      glm::vec3( 1.5f,  2.0f, -2.5f),
      glm::vec3( 1.5f,  0.2f, -1.5f),
      glm::vec3(-1.3f,  1.0f, -1.5f)
  	};

    Shader demoShader("../src/shaders/vertex.vs", "../src/shaders/fragment.fs");

    Texture tex("assets/wall.jpg");
    Texture secTex("assets/fire.jpg");

    demoShader.use();
    demoShader.setInt("texture1", 0);
  	demoShader.setInt("texture2", 1);

    glfwSetFramebufferSizeCallback(renderer.window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(renderer.window)) {
        renderer.processInput(renderer.window);
		    demoShader.use();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        glActiveTexture(GL_TEXTURE0);
    		glBindTexture(GL_TEXTURE_2D, tex.texID);
    		glActiveTexture(GL_TEXTURE1);
    		glBindTexture(GL_TEXTURE_2D, secTex.texID);

        // create transformations
        glm::mat4 view;
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), (float)con.xRes / (float)con.yRes, 0.1f, 100.0f);
        view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        // pass transformation matrices to the shader
        demoShader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        demoShader.setMat4("view", view);

        renderer.drawCube();
    		for (unsigned int i = 0; i < 10; i++) {
    			// calculate the model matrix for each object and pass it to shader before drawing
    			glm::mat4 model;
    			model = glm::translate(model, cubePositions[i]);
    			float angle = 20.0f * i;
    			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
    			//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    			demoShader.setMat4("model", model);
    			glDrawArrays(GL_TRIANGLES, 0, 36);
    		}
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
