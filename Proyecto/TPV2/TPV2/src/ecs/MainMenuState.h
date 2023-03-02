#pragma once
#include "Manager.h"
#include "../sdlutils/Font.h"
class Game;
class MainMenuState :public Manager
{
private:
	Game* game;
	Font* font = nullptr;
	SDL_Color s = { 255,0,0 };

public:
	MainMenuState(Game* game);
	virtual ~MainMenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
	virtual string getStateID() { return "MENU"; };
};

