#include "AsteroidManager.h"
#include "PlayState.h"
#include "Game.h"
void AsteroidManager::createAsteroids(int n) // We create n asteroid in scene
{
	nAsteroids += n;
	for (int i = 0; i < n; i++)
	{
		asteroid = new Entity();

		int gen = sdlutils().rand().nextInt(1, 4); // Number of generations of the asteoird
		asteroid->addComponent<Generations>(GENERATIONS_H, gen);
		
		// Code to decide where the asteoird spawn
		int positionProb = sdlutils().rand().nextInt(0, 4);
		Vector2D posIni;
		switch (positionProb) {
			case 0: // Upside
				posIni = Vector2D(sdlutils().rand().nextInt(0, WIN_WIDTH), sdlutils().rand().nextInt(0, 100)); 
				break;
			case 1: // Rightside
				posIni =  Vector2D(sdlutils().rand().nextInt(WIN_WIDTH - 100, WIN_WIDTH), sdlutils().rand().nextInt(0, WIN_HEIGHT));
				break;
			case 2: // Leftside
				posIni =  Vector2D(sdlutils().rand().nextInt(0, 100), sdlutils().rand().nextInt(0, WIN_HEIGHT));
				break;
			case 3: // Downside
				posIni =  Vector2D(sdlutils().rand().nextInt(0, WIN_WIDTH), sdlutils().rand().nextInt(WIN_HEIGHT - 100, WIN_HEIGHT));
				break;
		}

		Vector2D h =  Vector2D(WIN_WIDTH / 2, WIN_HEIGHT / 2);
		Vector2D r =  Vector2D(sdlutils().rand().nextInt(-100, 101), sdlutils().rand().nextInt(-100, 101));
		Vector2D c = h + r;
		float speed = sdlutils().rand().nextInt(5, 10) / 10.0f;
		Vector2D velIni = (c - posIni).normalize() * speed;
		float width = 17 * gen, height = 20 * gen, rotationIni = 1;

		asteroid->addComponent<Transform>(TRANSFORM_H, posIni, velIni, width, height, rotationIni);
		
		asteroid->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDE_H);
		
		Texture* texture2;
		if(sdlutils().rand().nextInt(0, 10) < 3)
		{
			asteroid->addComponent<Follow>(FOLLOW_H, mngr_->getEntities()[0]);
			texture2 = &SDLUtils::instance()->images().at("asteroidGold");
		}
		else {
			texture2 = &SDLUtils::instance()->images().at("asteroid");
		}

		asteroid->addComponent<FramedImage>(FRAMEDIMAGE_H, texture2, ASTEROID_WIDTH_FRAME, ASTEROID_HEIGHT_FRAME);
		asteroid->addToGroup(_grp_ASTEROIDS);

		mngr_->addEntity(asteroid); // We add entity to the scene
	}
}

AsteroidManager::~AsteroidManager()
{
	
}

void AsteroidManager::destroyAllAsteroids() {
	for (auto& e : mngr_->getEntities()) {
		if (e->hasGroup(_grp_ASTEROIDS)) {
			e->setAlive(false);
		}
	}


	nAsteroids = 0;
}


void AsteroidManager::onCollision(Entity* ent) { // Method that manage the collision of the asteroid
	int gen = ent->getComponent<Generations>(GENERATIONS_H)->getGenerations();
	if (gen > 1 && mngr_->getEntities().size() < 29) {
		for (int i = 0; i < 2; i++) {
			Transform* tr = ent->getComponent<Transform>(TRANSFORM_H);

			++nAsteroids;
			asteroid = new Entity();
			int newGen = gen - 1;
			asteroid->addComponent<Generations>(GENERATIONS_H, newGen);

			int newWidth = (tr->getW() / gen) * newGen, newHeight = (tr->getH() / gen) * newGen;

			auto r = sdlutils().rand().nextInt(0, 360);
			auto pos = tr->getPos(); //+ tr->getVel().rotate(r) * 2 * max(newWidth, newHeight);
			auto vel = tr->getVel().rotate(r) * 1.1f;

			asteroid->addComponent<Transform>(TRANSFORM_H, pos, vel, newWidth, newHeight, r);

			asteroid->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDE_H);

			Texture* texture2;
			if (sdlutils().rand().nextInt(0, 10) < 3)
			{
				asteroid->addComponent<Follow>(FOLLOW_H, mngr_->getEntities()[0]);
				texture2 = &SDLUtils::instance()->images().at("asteroidGold");
			}
			else {
				texture2 = &SDLUtils::instance()->images().at("asteroid");
			}

			int widthFrame = 85, heightFrame = 100;
			asteroid->addComponent<FramedImage>(FRAMEDIMAGE_H, texture2, widthFrame, heightFrame);
			asteroid->addToGroup(_grp_ASTEROIDS);

			mngr_->addEntity(asteroid);
		}
	}
	--nAsteroids;
	ent->setAlive(false);
}
