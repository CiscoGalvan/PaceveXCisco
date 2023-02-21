#pragma once
#include "Manager.h"
#include "Fighter.h"
class Game;
class PlayState : public Manager
{
private:
	bool gameover = false, win = false, nextLevelBool = false; // control booleans
	Game* game;
	
public:
	PlayState(Game* game1);
	~PlayState();
	virtual void render();
	virtual void handleEvents();
	virtual void update();
	virtual void refresh() {};
};
