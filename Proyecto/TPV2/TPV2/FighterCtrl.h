#pragma once
#ifndef FIGHTERCONTROL_H_
#define FIGHTERCONTROL_H_
#include "Component.h"
#include "src/sdlutils/InputHandler.h"
#include "Transform.h"
class Game;
class FighterCtrl : public Component
{
private:
	Game* game;
	Transform* trFighter;

public:
	FighterCtrl(Game* game_):game(game_){}
	void handleEvent(SDL_Event event);
	void initComponent();
};

#endif
