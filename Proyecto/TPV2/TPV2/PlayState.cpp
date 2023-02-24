#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game1) {
	game = game1;
	// We finally create the game objects 
	// We add all the objects to the GameObjects list
	if (!ents_.empty())
	{
		ents_.clear();
	}

	fighter = new Entity();
	Texture* texture = &SDLUtils::instance()->images().at("fighter");
	Vector2D posIni = new Vector2D(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	Vector2D velIni = new Vector2D(0, 0);
	float width = 88, height = 77, rotationIni = 1;
	int maxLifes = 5;
	fighter->addComponent<Transform>(TRANSFORM_H, posIni, velIni, width, height, rotationIni);
	fighter->addComponent<Image>(IMAGE_H, texture);
	fighter->addComponent<Health>(HEALTH_H, maxLifes, game);
	ctrl = fighter->addComponent<FighterCtrl>(FIGHTERCONTROL_H, game);
	fighter->addComponent<DeAccelerationComponent>(DEACCELERATIONCOMPONENT_H);
	fighter->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDCE_H);
	addEntity(fighter);
	
	
}
PlayState::~PlayState() {

}
void PlayState::update() {
	for (auto it : ents_)
	{
		it->update();
	}
}
void PlayState::render() {
	SDL_RenderClear(game->getRenderer());
	for (auto it : ents_) {
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
		ctrl->handleEvent(event);
	}
}
