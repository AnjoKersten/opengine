#ifndef CAMERA_H
#define CAMERA_H

#include <glad.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"

using namespace glm;

class Camera {
public:
  Camera();
  virtual ~Camera();
	void processInput(GLFWwindow* window);
	void update();

  mat4 view;
	mat4 projection;
private:
  vec3 cameraPos;
	vec3 cameraFront;
	vec3 cameraUp;

  float deltaTime = 0.0f;
	float lastFrame = 0.0f;
};

#endif
