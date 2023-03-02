#pragma once
#ifndef GUN_H_
#define GUN_H_
#include "../ecs/Component.h"
#include "../sdlutils/InputHandler.h"
#include "Transform.h"
#include "Image.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/Entity.h"
#include "DisableOnExit.h"
class Gun : public Component
{
private:
	float lastShootTime, rotacionBala, widthBala = 5,  heightBala = 20, cadence = 250;
	bool canShoot = true;
	Transform* trFighter;
	Texture* texture;
	Vector2D posBala, velBala;
	
public:
	Gun(): Component() {};
	void initComponent();
	void shoot();
	void update();
	void createBullet();
};

#endif
