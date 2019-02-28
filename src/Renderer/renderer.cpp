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

    config con;
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

void Renderer::DrawSkybox() {
  Skybox sky;
  sky.loadSkybox("engine/assets/Sprites/Skybox/front.tga", "engine/assets/Sprites/Skybox/bacl.tga", "engine/assets/Sprites/Skybox/bottom.tga",
    "engine/assets/Sprites/Skybox/top.tga", "engine/assets/Sprites/Skybox/left.tga", "engine/assets/Sprites/Skybox/right.tga");
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
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
