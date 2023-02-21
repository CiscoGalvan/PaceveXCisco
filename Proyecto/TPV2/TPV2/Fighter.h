#pragma once
#include "Entity.h"
#include "src/sdlutils/Texture.h"
#include "src/sdlutils/SDLUtils.h"
#include "Image.h"
#include "Transform.h"
#include "Health.h"
#include "FighterCtrl.h"
class Game;
class Fighter : public Entity {
private:
	Vector2D position{ 200, 150 }, velocity{ 0,0 };
	float width = 88, height = 77, rotation_ = 1;
	int maxLifes = 5;
	Transform* tr;
	FighterCtrl* ctrl;
	Texture* texture;
	Game* game_;
public:
	Fighter(Game* game);
	void initComponent();

	void handleEvent(SDL_Event event);
	
};

