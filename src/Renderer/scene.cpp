#include "scene.h"

Scene::Scene() {
	pCamera = new Camera(glm::vec3(0.0f, -1.5f, 2.5f));

	isRunning = true;
}

Scene::~Scene() {
	delete pCamera;
}
