#include "src/Core/core.h"
#include "game.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
	
    Core core;

    Game* game = new Game();

    glfwSetFramebufferSizeCallback(core.window, framebuffer_size_callback);

    // render loop
    while (game->isRunning) {
	core.run(game);
    }

    core.cleanUp();
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
