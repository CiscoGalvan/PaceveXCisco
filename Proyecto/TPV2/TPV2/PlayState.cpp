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
	gn = fighter->addComponent<Gun>(GUN_H);
	fighter->addComponent<FighterCtrl>(FIGHTERCONTROL_H);
	fighter->addComponent<DeAccelerationComponent>(DEACCELERATIONCOMPONENT_H);
	fighter->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDE_H);
	
	
	//Si no hacemos el setContext el manager es nulo todo el rato
	gn->setContext(fighter, this);
	//ctrl->initComponent();

	addEntity(fighter);

	astMngr_ = new AsteroidManager(this);
	astMngr_->createAsteroids(10);
	
	colMnrg_ = new CollisionManager(this, astMngr_);
	
}
PlayState::~PlayState() {

}
void PlayState::update() {
	if (astMngr_->getLastRespawnTime() + astMngr_->getTimeGen() < sdlutils().currRealTime())
	{
		astMngr_->setRespawn(true);
	}
	if (astMngr_->getRespawn())
	{
		astMngr_->setRespawn(false);
		astMngr_->setLastRespawnTime(sdlutils().currRealTime());
		astMngr_->addAsteroidFrecuently();
	}

	for (auto it : ents_)
	{
		for (auto it2 : ents_)
		{
			if ((it->hasComponent(FIGHTERCONTROL_H) || it->hasComponent(DISABLEONEXIT_H)) && it2->hasComponent(FOLLOW_H)) {

				colMnrg_->checkCollision(it2, it);
			}
		}
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

