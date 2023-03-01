#pragma once
//#include "Manager.h"
#include "Image.h"
#include "FighterCtrl.h"
//#include "Transform.h"
//#include "ShowAtOpposideSide.h"
#include "DeAccelerationComponent.h"
#include "Health.h"
#include "Gun.h"
#include "AsteroidManager.h"
class Game;
class PlayState : public Manager
{
private:
	bool gameover = false, win = false, nextLevelBool = false; // control booleans
	Game* game;
	Entity* fighter = nullptr;
	Entity* asteroid = nullptr;
	AsteroidManager* astMngr_;
	Gun* gn=nullptr;
public:
	PlayState(Game* game1);
	~PlayState();
	virtual void render();
	virtual void handleEvents();
	virtual void update();
	virtual void refresh();
	inline Entity* getFighter() { return fighter; }
};
