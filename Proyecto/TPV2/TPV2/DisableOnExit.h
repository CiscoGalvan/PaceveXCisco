#pragma once
#ifndef DISABLEONEXIT_H_
#define DISABLEONEXIT_H_
#include "Component.h"
#include "Transform.h"
#include "Entity.h"
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
