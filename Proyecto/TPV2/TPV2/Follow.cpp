#include "Follow.h"


Follow::Follow(Entity* fighter_)
{
	fighter = fighter_;
}
void Follow::initComponent()
{
	trFighter = fighter->getComponent<Transform>(TRANSFORM_H);
	trAsteroid = ent_->getComponent<Transform>(TRANSFORM_H);
	
}

void Follow::update()
{
	trAsteroid->setVel(trAsteroid->getVel().rotate(trAsteroid->getVel().angle(trFighter->getPos() - trAsteroid->getPos()) > 0 ? 1.0f : -1.0f));
	//trAsteroid->setVel(trFighter->getVel().angle(trFighter->getPos()-trAsteroid->getPos()) > 0? 1.0f : -1.0f);
}