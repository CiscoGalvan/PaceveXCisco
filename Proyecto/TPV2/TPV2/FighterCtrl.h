#pragma once
#ifndef FIGHTERCONTROL_H_
#define FIGHTERCONTROL_H_
#include "Component.h"
#include "src/sdlutils/InputHandler.h"
#include "Transform.h"
#include "src/sdlutils/SDLUtils.h"
#include "Gun.h"
class Game;
class FighterCtrl : public Component
{
private:
	Game* game;
	Transform* trFighter;
	Gun* gn_;
	float acceleration = 0.2f;

public:
	FighterCtrl(Game* game_): Component(), game(game_){}
	void handleEvent(SDL_Event event);
	void initComponent();
	void update()
	{
		/*std::cout << trFighter->getR()<<std::endl;*/
	}
};

#endif
