#include "FighterCtrl.h"
#include "Game.h"
void FighterCtrl::handleEvent(SDL_Event event)
{
	InputHandler::instance()->update(event);

	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1)cout << "LETS GOOOOOOO";
}