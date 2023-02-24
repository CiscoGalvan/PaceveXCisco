#include "ShowAtOpposideSide.h"
#include "Entity.h"
#include "Game.h"			//para pillar las constantes


void ShowAtOpposideSide::initComponent()
{
	transformShip = ent_->getComponent<Transform>(TRANSFORM_H);
}

void ShowAtOpposideSide::update()
{
	if (transformShip->getPos().getX()- transformShip->getW() >WIN_WIDTH)
	{
		transformShip->setPos(Vector2D(-transformShip->getW(), transformShip->getPos().getY()));
	}
	else if(transformShip->getPos().getX() + transformShip->getW() < 0)
	{
		transformShip->setPos(Vector2D(WIN_WIDTH, transformShip->getPos().getY()));
	}
	else if (transformShip->getPos().getY() - transformShip->getH() > WIN_HEIGHT)
	{
		transformShip->setPos(Vector2D(transformShip->getPos().getX(), 0));
	}
	else if(transformShip->getPos().getY() + transformShip->getH() < 0)
	{
		transformShip->setPos(Vector2D(transformShip->getPos().getX(), WIN_HEIGHT));
	}

}

