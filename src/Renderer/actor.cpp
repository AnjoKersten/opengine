#include "actor.h"

Actor::Actor() {
	transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.scale = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
}

Actor::~Actor() {
	
}


