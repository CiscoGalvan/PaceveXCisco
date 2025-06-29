#include "DeAccelerationComponent.h"
#include "Entity.h"
void DeAccelerationComponent::update() {

	//If the module of the velocity vector is less than a limit
	//If not it will reduce it�s velocity
	if (sqrt(pow(transformShip->getVel().getX(), 2) + pow(transformShip->getVel().getY(), 2)) < limit)
	{
		transformShip->setVel(Vector2D(0, 0));
	}
	else
	{
		transformShip->setVel(Vector2D(transformShip->getVel().getX() * deceleration, transformShip->getVel().getY() * deceleration));
	}
}

void DeAccelerationComponent::render() {

}

void DeAccelerationComponent::initComponent() {
	transformShip = ent_->getComponent<Transform>(TRANSFORM_H);
}