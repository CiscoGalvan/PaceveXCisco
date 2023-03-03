#pragma once
#include "Manager.h"
#include "AsteroidManager.h"
#include "src/utils/Collisions.h"

class Manager;
class CollisionManager
{
private:
	Manager* mngr_;
	AsteroidManager* astMnrg_;
public:
	CollisionManager(Manager* manager, AsteroidManager* astManager) : mngr_(manager), astMnrg_(astManager) {};
	void checkCollision(Entity* ast, Entity* ent);
};


