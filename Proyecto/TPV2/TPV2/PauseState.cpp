#include "PauseState.h"
#include "Game.h"
PauseState::PauseState(Game* game) {
	this->game = game;

	//DEJAR LA LISTA OBJETOS VACIA
	entities.clear();
}

PauseState::~PauseState() {

}
void PauseState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : entities) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}
void PauseState::update()
{
	for (auto it : entities) {
		it->update();
	}
}

void PauseState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->setExit();
	}

}