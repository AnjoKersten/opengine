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
	glfwSetKeyCallback(window, keyHandler);
}

void Input::update() {
	glfwPollEvents();
}

bool Input::getKey(int kCode) {
	return Input::getInstance()->_keys[kCode];
}

bool Input::getKeyDown(int kCode) {
	if (Input::getInstance()->_keys[kCode] && !Input::getInstance()->_keysDown[kCode]) {
		Input::getInstance()->_keysDown[kCode] = true;
		return true;
	} else if (!Input::getInstance()->_keys[kCode] && Input::getInstance()->_keysDown[kCode]) {
		Input::getInstance()->_keysDown[kCode] = false;
	}
	return false;
}

void Input::keyHandler(GLFWwindow* window, int key, int scanCode, int action, int mode) {
		
}
