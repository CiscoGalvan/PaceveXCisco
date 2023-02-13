#include "MainMenuState.h"
#include "Game.h"
MainMenuState::MainMenuState(Game* game) {
	this->game = game;

	//DEJAR LA LISTA OBJETOS VACIA
	entities.clear();

}
MainMenuState::~MainMenuState() {

}
void MainMenuState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : entities) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}
void MainMenuState::update()
{
	for (auto it : entities) {
		it->update();
	}
}

void MainMenuState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->setExit();
	}
}