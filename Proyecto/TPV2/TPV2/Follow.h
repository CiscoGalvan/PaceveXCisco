#pragma once
#ifndef FOLLOW_H_
#define FOLLOW_H_
#include "Component.h"
#include "Transform.h"
#include "Image.h"
#include "src/sdlutils/SDLUtils.h"
#include "Entity.h"
#include "Manager.h"
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
