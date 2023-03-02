#include "MainMenuState.h"
#include "Game.h"
MainMenuState::MainMenuState(Game* game) {
	this->game = game;

	//DEJAR LA LISTA OBJETOS VACIA
	if (!ents_.empty())
	{
		ents_.clear();
	}
	font = &SDLUtils::instance()->fonts().at("ARIAL16");
}
MainMenuState::~MainMenuState() {

}
void MainMenuState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : ents_) {
		it->render();
	}
	font->render(SDLUtils::instance()->renderer(), "PRESS SPACE TO CONTINUE", (WIN_WIDTH / 2) - 100, WIN_HEIGHT / 2, s);
	SDL_RenderPresent(game->getRenderer());
}
void MainMenuState::update()
{
	for (auto it : ents_) {
		it->update();
	}
}

void MainMenuState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->setExit();
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) game->playFunction(game);
	}
}