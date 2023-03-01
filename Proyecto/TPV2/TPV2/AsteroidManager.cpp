#include "AsteroidManager.h"
#include "PlayState.h"
#include "Game.h"
void AsteroidManager::createAsteroids(int n)
{
	nAsteroids = n;
	for (int i = 0; i < n; i++)
	{
		asteroid = new Entity();
		Texture* texture2;
		int positionProb = sdlutils().rand().nextInt(0, 4);
		Vector2D posIni2;
		switch (positionProb) {
			case 0: // Franja superior
				posIni2 = new Vector2D(sdlutils().rand().nextInt(0, WIN_WIDTH), sdlutils().rand().nextInt(0, 100)); 
				break;
			case 1: // Franja derecha
				posIni2 = new Vector2D(sdlutils().rand().nextInt(WIN_WIDTH - 100, WIN_WIDTH), sdlutils().rand().nextInt(0, WIN_HEIGHT));
				break;
			case 2: // Franja izquierda
				posIni2 = new Vector2D(sdlutils().rand().nextInt(0, 100), sdlutils().rand().nextInt(0, WIN_HEIGHT));
				break;
			case 3: // Franja inferior
				posIni2 = new Vector2D(sdlutils().rand().nextInt(0, WIN_WIDTH), sdlutils().rand().nextInt(WIN_HEIGHT - 100, WIN_HEIGHT));
				break;
		}
		Vector2D h = new Vector2D(WIN_WIDTH / 2, WIN_HEIGHT / 2);
		Vector2D r = new Vector2D(sdlutils().rand().nextInt(-100, 101), sdlutils().rand().nextInt(-100, 101));
		Vector2D c = h + r;
		float speed = sdlutils().rand().nextInt(1, 10) / 10.0f;
		Vector2D velIni2 = (c - posIni2).normalize() * speed;
		float width2 = 85, height2 = 100, rotationIni2 = 1;

		asteroid->addComponent<Transform>(TRANSFORM_H, posIni2, velIni2, width2, height2, rotationIni2);
		
		asteroid->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDE_H);
		
		if(sdlutils().rand().nextInt(0, 10) < 3)
		{
			asteroid->addComponent<Follow>(FOLLOW_H, mngr_->getEntities()[0]);
			texture2 = &SDLUtils::instance()->images().at("asteroidGold");
		}
		else {
			texture2 = &SDLUtils::instance()->images().at("asteroid");
		}
		asteroid->addComponent<FramedImage>(FRAMEDIMAGE_H, texture2);
	
		cout << mngr_->getEntities().size();
		mngr_->addEntity(asteroid);
		
	}
}
