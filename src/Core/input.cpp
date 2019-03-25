#include "input.h" 
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
	
}
