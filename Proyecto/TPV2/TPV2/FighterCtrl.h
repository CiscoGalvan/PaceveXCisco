#pragma once
#ifndef FIGHTERCONTROL_H_
#define FIGHTERCONTROL_H_
#include "Component.h"
#include "src/sdlutils/InputHandler.h"
class Game;
class FighterCtrl : public Component
{
private:
	Game* game;


public:
	FighterCtrl(Game* game_):game(game_){}
	void handleEvent(SDL_Event event);

	
};

#endif
