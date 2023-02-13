#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game1, bool load) {
	game = game1;
	// We finally create the game objects 

	// We add all the objects to the GameObjects list
	if (!entities.empty())
	{
		entities.clear();
	}
}
PlayState::~PlayState() {

}
void PlayState::update() {
	for (auto it : entities)
	{
		it->update();
	}
}
void PlayState::render() {
	SDL_RenderClear(game->getRenderer());
	for (auto it : entities) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}

//Function that handle the events
void PlayState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			game->pauseFunction(game);
		}
		if (event.type == SDL_QUIT) game->setExit();
	}
}
