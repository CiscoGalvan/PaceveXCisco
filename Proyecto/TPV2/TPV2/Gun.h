#pragma once
#ifndef GUN_H_
#define GUN_H_
#include "Component.h"
#include "src/sdlutils/InputHandler.h"
#include "Transform.h"
#include "Image.h"
#include "src/sdlutils/SDLUtils.h"
#include "Entity.h"
#include "DisableOnExit.h"
class Gun : public Component
{
private:
	float lastShootTime, rotacionBala, widthBala = 29,  heightBala = 66;
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
