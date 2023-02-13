#pragma once
#include "GameState.h"

class Game;
class PlayState : public GameState
{
private:
	bool gameover = false, win = false, nextLevelBool = false; // control booleans
	Game* game;

public:
	PlayState(Game* game1, bool load);
	~PlayState();
	virtual void render();
	virtual void handleEvents();
	virtual void update();
	virtual void refresh() {};
};
