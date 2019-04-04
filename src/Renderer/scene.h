#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

class Scene {
public:
	Scene();
	virtual ~Scene();

	void start() { isRunning = true; };
	void stop() { isRunning = false; };

	Camera* camera() { return pCamera; };
private:
	bool isRunning;
	Camera* pCamera;

};

#endif
