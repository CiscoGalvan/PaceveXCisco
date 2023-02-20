#pragma once
#include "Manager.h"

class Game;
class PauseState :public Manager {
private:
	Game* game;
public:

	PauseState(Game* game);
	virtual ~PauseState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};


