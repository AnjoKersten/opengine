#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "actor.h"

class Scene : public Actor {
public:
	Scene();
	virtual ~Scene();

	void start() { isRunning = true; };
	void stop() { isRunning = false; };

	Camera* camera() { return pCamera; };

	bool isRunning;
private:
	Camera* pCamera;
};

#endif
