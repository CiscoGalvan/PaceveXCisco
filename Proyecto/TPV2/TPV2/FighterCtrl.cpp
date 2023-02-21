#include "FighterCtrl.h"
#include "Game.h"
void FighterCtrl::handleEvent(SDL_Event event)
{
	InputHandler::instance()->update(event);

	if (event.type == SDL_KEYDOWN)
		if (event.key.keysym.sym == SDLK_UP) {
			cout << "arriba";
			//trFighter->setVel(Vector2D(cos(trFighter->getR()), sin(trFighter->getR())));
			//SDLUtils::instance()->soundEffects().at("../../../resources/sound/thrust.wav").play();
		}
		if (event.key.keysym.sym == SDLK_LEFT) {
			trFighter->setR(trFighter->getR() - 5);
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			trFighter->setR(trFighter->getR() + 5);
		}
}

void FighterCtrl::initComponent() {
	trFighter = ent_->getComponent<Transform>(TRANSFORM_H);
}