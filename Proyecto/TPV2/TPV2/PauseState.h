#pragma once
#include "GameState.h"

class Game;
class PauseState :public GameState
{
private:
	Game* game;
public:

	PauseState(Game* game);
	virtual ~PauseState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};


