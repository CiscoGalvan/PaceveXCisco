#include "Gun.h"
#include "PlayState.h"

void Gun::initComponent()
{
	trFighter = ent_->getComponent<Transform>(TRANSFORM_H);
	texture = &SDLUtils::instance()->images().at("fire");
}

void Gun::update()
{
	if (lastShootTime + 250 < sdlutils().currRealTime())
	{
		canShoot = true;
	}

}

void Gun::createBullet()
{
	Entity* bullet = new Entity();
    posBala = trFighter->getPos()
		+ Vector2D(trFighter->getW() / 2.0f, trFighter->getH() / 2.0f)
		- Vector2D(0.0f, trFighter->getW() / 2.0f + 5.0f + 12.0f).rotate(trFighter->getR())
		- Vector2D(2.0f, 10.0f);
    velBala = Vector2D(0.0f, -1.0f).rotate(trFighter->getR()) * (trFighter->getVel().magnitude() + 5.0f);
	rotacionBala = trFighter->getR();

	bullet->addComponent<Transform>(TRANSFORM_H, posBala, velBala, widthBala, heightBala, rotacionBala);
	bullet->addComponent<Image>(IMAGE_H, texture);
	bullet->addComponent<DisableOnExit>(DISABLEONEXIT_H);
	mngr_->addEntity(bullet);
}
void Gun::shoot()
{
	if (canShoot)
	{
		//SDLUtils::instance()->soundEffects().at("fire").play();
		canShoot = false;
		lastShootTime = sdlutils().currRealTime();

		createBullet();
	}
		
	
	
}