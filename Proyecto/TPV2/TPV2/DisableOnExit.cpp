#include "DisableOnExit.h"
#include "Game.h"
void DisableOnExit::initComponent()
{
	trBullet = ent_->getComponent<Transform>(TRANSFORM_H);
}


void DisableOnExit::update()
{
	//If the transform bullet is outside the renderer it will be killed
	if (trBullet->getPos().getX()< -trBullet->getW() || trBullet->getPos().getX() > WIN_WIDTH || trBullet->getPos().getY() < -trBullet->getH() || trBullet->getPos().getY() > WIN_HEIGHT)
	{
		ent_->setAlive(false);
	}
}