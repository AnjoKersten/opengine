#include "input.h" 

Input* Input::instance = NULL;

Input::Input() {

}

Input::~Input() {

}

Input* Input::getInstance() {
	if (instance == NULL) {
		std::cout << "Instance made!" << std::endl;
		instance = new Input();
	}
	return instance;
}

void Input::init(GLFWwindow* window) {
	Input::getInstance()->window = window;

	//required callbacks
	glfwSetKeyCallback(window, _handleKey);
	glfwSetMouseButtonCallback(window, _handleMouseButton);
	glfwSetCursorPosCallback(window, _handleMouse);
	glfwSetScrollCallback(window, _handleScroll);
}

void Input::update() {
	glfwPollEvents();
}
