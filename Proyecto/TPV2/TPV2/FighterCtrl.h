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
	float acceleration = 0.2f;

public:
	FighterCtrl(Game* game_):game(game_){}
	void handleEvent(SDL_Event event);
	void initComponent();
	void update()
	{
		std::cout << trFighter->getR()<<std::endl;
	}
};

#endif
