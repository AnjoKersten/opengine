#ifndef CORE_H
#define CORE_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include "../config.h"
#include "../Renderer/scene.h"
#include "../Renderer/renderer.h"


class Core {
public:
	Core();
	virtual ~Core();
	GLFWwindow* window;
	void createWindow();
	void run(Scene* scene);
private:
	config con;
	Renderer renderer;

};

#endif
