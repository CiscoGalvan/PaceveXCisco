#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game1) {
	game = game1;
	init();
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
	gn = fighter->addComponent<Gun>(GUN_H);
	ctrl = fighter->addComponent<FighterCtrl>(FIGHTERCONTROL_H, game);
	//ctrl->setContext(fighter, this);
	fighter->addComponent<DeAccelerationComponent>(DEACCELERATIONCOMPONENT_H);
	fighter->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDCE_H);
	
	
	//Si no hacemos el setContext el manager es nulo todo el rato
	gn->setContext(fighter, this);
	//ctrl->initComponent();

	addEntity(fighter);


	for (int i = 0; i < 5; i++) {
		asteroid = new Entity();
		Texture* texture2 = &SDLUtils::instance()->images().at("asteroid");
		Vector2D posIni2 = new Vector2D((WIN_WIDTH / 2) + 50, WIN_HEIGHT / 2);
		Vector2D velIni2 = new Vector2D(1, 0);
		float width2 = 85, height2 = 100, rotationIni2 = 1;

		asteroid->addComponent<Transform>(TRANSFORM_H, posIni2, velIni2, width2, height2, rotationIni2);
		asteroid->addComponent<FramedImage>(FRAMEDIMAGE_H, texture2);
		asteroid->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDCE_H);
		asteroid->addComponent<Follow>(FOLLOW_H, fighter);

		addEntity(asteroid);
	}
	

	
}
PlayState::~PlayState() {

}
void PlayState::update() {

	cout << ents_.size();
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
		fighter->handleEvent(event);
	}
}

void PlayState::refresh() 
{
	ents_.erase(
		remove_if(ents_.begin(), ents_.end(), [](Entity* e) {
			if (e->isAlive()) {
				return false;
			}
			else {
				delete e;
				return true;
			}
			}),
		ents_.end());
}

