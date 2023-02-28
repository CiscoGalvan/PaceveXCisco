#include "AsteroidManager.h"
#include "PlayState.h"
#include "Game.h"
void AsteroidManager::createAsteroids(int n)
{
	nAsteroids = n;
	for (int i = 0; i < n; i++)
	{
		asteroid = new Entity();
		Texture* texture2 = &SDLUtils::instance()->images().at("asteroid");
		Vector2D posIni2 = new Vector2D((sdlutils().rand().nextInt(WIN_WIDTH-100, WIN_WIDTH)) , (sdlutils().rand().nextInt(WIN_HEIGHT-100, WIN_HEIGHT)));
		Vector2D velIni2 = new Vector2D(1+i, 0);
		float width2 = 85, height2 = 100, rotationIni2 = 1;

		asteroid->addComponent<Transform>(TRANSFORM_H, posIni2, velIni2, width2, height2, rotationIni2);
		asteroid->addComponent<FramedImage>(FRAMEDIMAGE_H, texture2);
		asteroid->addComponent<ShowAtOpposideSide>(SHOWATOPPOSIDESIDCE_H);
		
		if(sdlutils().rand().nextInt(0, 10) < 3)
		{
			asteroid->addComponent<Follow>(FOLLOW_H, mngr_->getEntities()[0]);
		}
	
		cout << mngr_->getEntities().size();
		mngr_->addEntity(asteroid);
		
	}
}
