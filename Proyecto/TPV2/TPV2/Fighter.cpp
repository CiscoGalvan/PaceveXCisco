#include "Fighter.h"
#include "Game.h"
Fighter::Fighter(Game* game) {
	game_ = game;
	texture = game->getTexture(Fighter1);
	addComponent<Transform>(TRANSFORM_H, position, velocity, width, height, rotation_);
	addComponent<Image>(IMAGE_H, texture);
}