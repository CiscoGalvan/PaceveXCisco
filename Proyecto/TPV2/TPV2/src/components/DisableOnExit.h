#pragma once
#ifndef DISABLEONEXIT_H_
#define DISABLEONEXIT_H_
#include "../ecs/Component.h"
#include "Transform.h"
#include "../ecs/Entity.h"
class DisableOnExit : public Component
{
private:
	
	Transform* trBullet;
public:
	DisableOnExit() : Component() {};
	void initComponent();
	void update();
};

#endif
