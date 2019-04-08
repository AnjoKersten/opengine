#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "src/Renderer/renderer.h"
#include "src/Renderer/scene.h"

class SceneManager {
public:
	SceneManager();
	virtual ~SceneManager();
	void loadScene(Scene* scene);
	void clearScene();
private:
	Renderer* _renderer;
};

#endif
