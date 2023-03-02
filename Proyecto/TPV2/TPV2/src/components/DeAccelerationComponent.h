#pragma once
#ifndef DEACCELERATIONCOMPONENT_H_
#define DEACCELERATIONCOMPONENT_H_
#include "../ecs/Component.h"
#include "Transform.h"
#include "../game/ecs.h"
class DeAccelerationComponent : public Component {
private:
	Transform* transformShip;
	float deceleration=0.995f;
public:
	DeAccelerationComponent() {}
	void initComponent();
	void update();
	void render();
	virtual ~DeAccelerationComponent() {}
};
#endif

