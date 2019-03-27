#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "src/Maths/transform.h"

class Actor {
public:
	Actor();
	virtual ~Actor();
	void childActor(Actor* actor) { actors.push_back(actor); };
	void removeChildActor(Actor* actor);
	std::vector<Actor*> getActors() { return actors; };
	int getActorCount() { return actors.size(); };
private:
	std::vector<Actor*> actors;

};

#endif
