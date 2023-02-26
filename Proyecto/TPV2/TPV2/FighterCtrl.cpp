#include "FighterCtrl.h"
#include "Game.h"
void FighterCtrl::handleEvent(SDL_Event event)
{
	InputHandler::instance()->update(event);

	
		if (event.key.keysym.sym == SDLK_UP) {
			trFighter->setVel(trFighter->getVel() + (Vector2D(0, -1).rotate(trFighter->getR()) * acceleration));
			//SDLUtils::instance()->soundEffects().at("thrust").play();
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