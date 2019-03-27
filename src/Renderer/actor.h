#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "src/Maths/transform.h"
#include "src/Core/input.h" 

class Actor {
public:
	bool active;
	Actor();
	virtual ~Actor();
	Input* input() { return _input; }
	void childActor(Actor* actor) { actors.push_back(actor); };
	void removeChildActor(Actor* actor);
	std::vector<Actor*> getActors() { return actors; };
	int getActorCount() { return actors.size(); };
private:
	std::vector<Actor*> actors;
	Input* _input;
	Transform transform;
};

#endif
