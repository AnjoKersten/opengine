#include "scenemanager.h"

SceneManager::SceneManager() {
	_renderer = new Renderer();
}

SceneManager::~SceneManager() {

}

void SceneManager::loadScene(Scene* scene) {
	_renderer->renderScene(scene);
}

void SceneManager::clearScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
