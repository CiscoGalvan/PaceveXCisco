#pragma once
#include "GameState.h"
class Game;
class MainMenuState :public GameState
{
private:
	Game* game;
public:
	MainMenuState(Game* game);
	~MainMenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};

