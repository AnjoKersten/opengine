#include "input.h" 

Input* Input::instance = NULL;

Input::Input() {
	for (int i = 0; i < GLFW_KEY_LAST; i++) {
		_keys[i] = false;
		_keysDown[i] = false;
	}
}

Input::~Input() {

}

Input* Input::getInstance() {
	if (instance == NULL) {
		std::cout << "Input instance made!" << std::endl;
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
	if (key >= 0 && key <= GLFW_KEY_LAST) {
		if (action == GLFW_PRESS) {
			Input::getInstance()->_keys[key] = true;
		} else if (action == GLFW_RELEASE) {
			Input::getInstance()->_keys[key] = false;
		}
	}	
}
