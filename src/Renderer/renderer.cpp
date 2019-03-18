#include "renderer.h"

/**
Constructor
Window creation
*/
Renderer::Renderer() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    window = glfwCreateWindow(con.xRes, con.yRes, "OPENGINE", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

Renderer::~Renderer() {

}

void Renderer::setupSkybox(Shader cubemapShader, Shader skyboxShader) {
    //Skybox VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(box.skyboxVertices), &box.skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //Shader config
    cubemapShader.use();
    cubemapShader.setInt("texture1", 0);
    skyboxShader.use();
    skyboxShader.setInt("skybox", 0);
}

void Renderer::drawSkybox(glm::mat4 view, glm::mat4 projection, Shader skyboxShader) {
    //Shader skyboxShader("../Shaders/skyboxVertex.vs", "../Shaders/skyboxFrag.fs");
    unsigned int cubemapTexture = box.loadSkybox(faces); 
    glDepthFunc(GL_LEQUAL);
    skyboxShader.use();
    skyboxShader.setMat4("view", view);
    skyboxShader.setMat4("projection", projection);
    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default
}

/**
 Input to close the window.
 Input key is the escape button.
 The function expects a window.
 */
void Renderer::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

/**
 A function to clean up the window before it's being closed.
 */
void Renderer::cleanUp() {
    glDeleteVertexArrays(1, &skyboxVAO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &skyboxVAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
