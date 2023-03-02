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

	font = &SDLUtils::instance()->fonts().at("ARIAL16");

	fighter = new Entity();
	Texture* texture = &SDLUtils::instance()->images().at("fighter");
	
	Vector2D velIni = new Vector2D(0, 0);
	float width = 44, height = 38.5, rotationIni = 1;
	Vector2D posIni = new Vector2D(WIN_WIDTH / 2 - width / 2, WIN_HEIGHT / 2 - height / 2);
	int maxLifes = 2;
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
	astMngr_->createAsteroids(1);
	
	colMnrg_ = new CollisionManager(this, astMngr_);
	
}
PlayState::~PlayState() {

}
void PlayState::update() {
	if (!gameover)
	{
		cout << numAst<<endl;
		if (astMngr_->getLastRespawnTime() + astMngr_->getTimeGen() < sdlutils().currRealTime())
		{
			astMngr_->setRespawn(true);
		}
		if (astMngr_->getRespawn())
		{
			astMngr_->setRespawn(false);
			astMngr_->setLastRespawnTime(sdlutils().currRealTime());
			//astMngr_->addAsteroidFrecuently();
		}

		for (auto it : ents_)
		{
			if (!ents_.empty())
			{
				it->update();
				for (auto it2 : ents_)
				{
					if (!ents_.empty())
					{
						if ((it->hasComponent(FIGHTERCONTROL_H) || it->hasGroup(_grp_BULLETS)) && it2->hasGroup(_grp_ASTEROIDS)) {

							colMnrg_->checkCollision(it2, it);
						}
					}
					
				}

			}	
		}
		Win();
	}
	

	
}
void PlayState::render() {
	SDL_RenderClear(game->getRenderer());
	for (auto it : ents_) {
		it->render();
	}


	if (gameover)
	{
		SDL_Color s = { 255,0,0 };
		font->render(SDLUtils::instance()->renderer(), "PRESS SPACE TO CONTINUE", WIN_WIDTH / 2, WIN_HEIGHT / 2,s);
	}

	SDL_RenderPresent(game->getRenderer());
}



//Function that handle the events
void PlayState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		if (!gameover)
		{
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			{
				game->pauseFunction(game);
			}
			if (event.type == SDL_QUIT) game->setExit();
			fighter->handleEvent(event);
		}
		
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		{
			gameover = false;
			
		}
	
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

void PlayState::Win()
{
	if (numAst == 0)
	{
		SDL_Color s = { 255,0,0 };
		font->render(SDLUtils::instance()->renderer(), "YOUR WIN!", (WIN_WIDTH / 2), (WIN_HEIGHT / 2) + 100, s);
		SDL_RenderPresent(game->getRenderer());
		SDL_Delay(5000);
		game->returnToMainMenu(game);
	}
}