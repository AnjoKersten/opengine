#ifndef CORE_H
#define CORE_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include "../config.h"

class Core {
public:
	Core();
	virtual ~Core();
	GLFWwindow* window;
	void createWindow();
private:
	config con;
};

#endif
