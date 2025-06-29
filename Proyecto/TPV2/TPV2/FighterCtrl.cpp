#include "FighterCtrl.h"
FighterCtrl::FighterCtrl() : Component() {

	//We set the volume of the sound
	sound->setVolume(50);
}

void FighterCtrl::handleEvent(SDL_Event event)
{
	InputHandler::instance()->update(event);

	
	//We handle the events for the Fighter Input
		if (event.key.keysym.sym == SDLK_UP) {
			if (sqrt(pow(trFighter->getVel().getX(), 2) + pow(trFighter->getVel().getY(), 2)) < speedLimit) {
				trFighter->setVel(trFighter->getVel() + (Vector2D(0, -1).rotate(trFighter->getR()) * acceleration));
			}
			else {
				trFighter->setVel(trFighter->getVel().normalize() * speedLimit);
			}
			sound->play();
		}
		if (event.key.keysym.sym == SDLK_LEFT) {
			trFighter->setR(trFighter->getR() - 5.0f);
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			trFighter->setR(trFighter->getR() + 5.0f);
		}
	

		if (event.key.keysym.sym == SDLK_s)
		{
			gn_->shoot();
		}
}

void FighterCtrl::initComponent() {
	trFighter = ent_->getComponent<Transform>(TRANSFORM_H);
	gn_ = ent_->getComponent<Gun>(GUN_H);
}