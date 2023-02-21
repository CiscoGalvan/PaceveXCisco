#include "Fighter.h"
#include "Game.h"
Fighter::Fighter(Game* game) {
	game_ = game;
	texture = game->getTexture(Fighter1);
	tr = addComponent<Transform>(TRANSFORM_H, position, velocity, width, height, rotation_);
	addComponent<Image>(IMAGE_H, texture);
	
	addComponent<Health>(HEALTH_H, maxLifes,game);
	ctrl = addComponent<FighterCtrl>(FIGHTERCONTROL_H, game);
	addComponent<DeAccelerationComponent>(DEACCELERATIONCOMPONENT_H);

}
void Fighter::handleEvent(SDL_Event event)
{
	ctrl->handleEvent(event);
}