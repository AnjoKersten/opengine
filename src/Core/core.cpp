#include "core.h"

Core::Core() {
	this->createWindow();
}

Core::~Core() {
	
}

void Core::createWindow() {
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

void Core::run(Scene* scene) {
	renderer.processInput(window);
	scene->camera()->processInput(window);

	renderer.renderScene(scene, window);
	if (glfwWindowShouldClose(window)) { scene->stop(); }
}

void Core::cleanUp() {
	renderer.cleanUp();
}
