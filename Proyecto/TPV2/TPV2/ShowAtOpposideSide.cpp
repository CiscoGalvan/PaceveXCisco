#include "ShowAtOpposideSide.h"
#include "Entity.h"
#include "Game.h"			//para pillar las constantes


void ShowAtOpposideSide::initComponent()
{
	transform = ent_->getComponent<Transform>(TRANSFORM_H);
}

void ShowAtOpposideSide::update()
{
	if (transform->getPos().getX()- transform->getW() >WIN_WIDTH)
	{
		transform->setPos(Vector2D(-transform->getW(), transform->getPos().getY()));
	}
	else if(transform->getPos().getX() + transform->getW() < 0)
	{
		transform->setPos(Vector2D(WIN_WIDTH, transform->getPos().getY()));
	}
	else if (transform->getPos().getY() - transform->getH() > WIN_HEIGHT)
	{
		transform->setPos(Vector2D(transform->getPos().getX(), 0));
	}
	else if(transform->getPos().getY() + transform->getH() < 0)
	{
		transform->setPos(Vector2D(transform->getPos().getX(), WIN_HEIGHT));
	}

}

