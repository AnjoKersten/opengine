#ifndef GAME_H
#define GAME_H

#include <src/Renderer/scene.h>
#include <src/Core/scenemanager.h>
#include "menu.h"
#include <iostream>

class Game : public Scene {
public:
	Game();
	virtual ~Game();
private:
	SceneManager sceneManager;
};

#endif
