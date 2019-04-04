#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "src/Core/input.h" 
#include "src/Model/model.h"

class Actor {
public:
	Actor* parent;
	bool active;
	Model* model = NULL;
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;
	Actor();
	virtual ~Actor();
	Input* input() { return _input; }
	void childActor(Actor* actor) { actors.push_back(actor); };
	void removeChildActor(Actor* actor);
	std::vector<Actor*> actors;
	int getActorCount() { return actors.size(); };
	void addModel(GLchar* path);
private:
	Input* _input;
};

#endif
