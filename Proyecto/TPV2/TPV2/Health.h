#pragma once
#ifndef HEALTH_H_
#define HEALTH_H_
#include "Component.h"
#include "src/sdlutils/Texture.h"
class Game;
class Health : public Component
{
private:

	int maxLives;
	int lives;
	Texture* texture;
	Game* game;


public:
	Health(int maxLifes_, Game* game);
	~Health(){}

	void render();

	inline void quitLife() { --lives; }
	inline void resetLifes() { lives = maxLives; }
	inline int getLifes() { return lives; }
};

#endif

