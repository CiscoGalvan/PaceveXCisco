#include "ShowAtOpposideSide.h"
#include "../ecs/Entity.h"
#include "../game/Game.h"			//para pillar las constantes


void ShowAtOpposideSide::initComponent()
{
	transform = ent_->getComponent<Transform>(TRANSFORM_H);
}

void ShowAtOpposideSide::update()
{
	if (transform->getPos().getX() > WIN_WIDTH) // Rightside
	{
		transform->setPos(Vector2D(-transform->getW(), transform->getPos().getY()));
	}
	else if (transform->getPos().getX() + transform->getW() < 0) // Leftside
	{
		transform->setPos(Vector2D(WIN_WIDTH, transform->getPos().getY()));
	}
	else if (transform->getPos().getY() > WIN_HEIGHT) // Downside
	{
		transform->setPos(Vector2D(transform->getPos().getX(), -transform->getH()));
	}
	else if(transform->getPos().getY() + transform->getH() < 0) // Upside
	{
		transform->setPos(Vector2D(transform->getPos().getX(), WIN_HEIGHT));
	}

}

