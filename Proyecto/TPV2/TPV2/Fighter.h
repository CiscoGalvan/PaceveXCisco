#pragma once
#include "Entity.h"
#include "src/sdlutils/Texture.h"
#include "src/sdlutils/SDLUtils.h"
#include "Image.h"
class Game;
class Fighter : public Entity {
private:
	Vector2D position{ 50, 50 }, velocity{ 0,0 };
	float width = 88, height = 77, rotation_ = 1;
	Texture* texture;
	Game* game_;
public:
	Fighter(Game* game);
};

