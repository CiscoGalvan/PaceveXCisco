#pragma once

#include "../components/Image.h"
#include "../components/FighterCtrl.h"
#include "../components/DeAccelerationComponent.h"
#include "../components/Health.h"
#include "../components/Gun.h"
#include "AsteroidManager.h"
#include "CollisionManager.h"
#include "../sdlutils/Font.h"
class Game;
class PlayState : public Manager
{
private:
	bool gameover = false, win = false, nextLevelBool = false; // control booleans
	Game* game;
	Entity* fighter = nullptr;
	Entity* asteroid = nullptr;
	AsteroidManager* astMngr_;
	CollisionManager* colMnrg_;
	
	Gun* gn=nullptr;
	Font* font = nullptr;
public:
	PlayState(Game* game1);
	virtual ~PlayState();
	virtual void render();
	virtual void handleEvents();
	virtual void update();
	inline void setGameover(bool newValue) { gameover = newValue; }
	inline Game* getGame() { return game; }
	void Win();
	virtual string getStateID() { return "PLAY"; };
};
