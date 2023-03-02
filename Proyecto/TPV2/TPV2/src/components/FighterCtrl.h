#pragma once
#ifndef FIGHTERCONTROL_H_
#define FIGHTERCONTROL_H_
#include "../ecs/Component.h"
#include "../sdlutils/InputHandler.h"
#include "Transform.h"
#include "../sdlutils/SDLUtils.h"
#include "Gun.h"
class FighterCtrl : public Component
{
private:
	Transform* trFighter;
	Gun* gn_;
	float acceleration = 0.2f, speedLimit = 3.0f;
	SoundEffect* sound = &SDLUtils::instance()->soundEffects().at("thrust");

public:
	FighterCtrl();
	void handleEvent(SDL_Event event);
	void initComponent();
};

#endif
