#include "actor.h"

Actor::Actor() {
	transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.scale = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	active = true;
}

Actor::~Actor() {
	
}

void Actor::removeChildActor(Actor* actor) {
	for (int i = 0; i < actors.size(); i++) {
		if (actors[i] == actor) {
			actors.erase(actors.begin() + i);
			break;
		}	
	}
}

void Actor::addModel(GLchar* path) {
	model = new Model(path);
}
