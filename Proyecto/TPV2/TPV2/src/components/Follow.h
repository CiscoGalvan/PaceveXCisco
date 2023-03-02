#pragma once
#ifndef FOLLOW_H_
#define FOLLOW_H_
#include "../ecs/Component.h"
#include "Transform.h"
#include "Image.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
class Follow : public Component
{
private:
	Transform* trFighter;
	Transform* trAsteroid;
	Entity* fighter;
public:
	Follow(Entity* fighter);
	void update();

	void initComponent();

};

#endif
