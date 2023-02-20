#pragma once
#ifndef DEACCELERATIONCOMPONENT_H_
#define DEACCELERATIONCOMPONENT_H_
#include "Component.h"
#include "Transform.h"
#include "ecs.h"
class DeAccelerationComponent : public Component {
private:
	Transform* transformShip;
	float deceleration;
public:
	DeAccelerationComponent() {}
	void initComponent();
	void update();
	void render();
	virtual ~DeAccelerationComponent() {}
};
#endif

