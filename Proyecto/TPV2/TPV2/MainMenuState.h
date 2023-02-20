#pragma once
#include "Manager.h"
class Game;
class MainMenuState :public Manager
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

