#include "PauseState.h"
#include "Game.h"
PauseState::PauseState(Game* game) {
	this->game = game;

	//DEJAR LA LISTA OBJETOS VACIA
	if (!ents_.empty())
	{
		ents_.clear();
	}
}

PauseState::~PauseState() {

}
void PauseState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : ents_) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}
void PauseState::update()
{
	for (auto it : ents_) {
		it->update();
	}
}

void PauseState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->exitFunction(game);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		{
			game->returnToGame(game);
		}
	}

}