#pragma once
#ifndef DEACCELERATIONCOMPONENT_H_
#define DEACCELERATIONCOMPONENT_H_
#include "Component.h"
#include "Transform.h"
#include "ecs.h"
class DeAccelerationComponent : public Component {
private:

	//We use the transform of the ship
	Transform* transformShip;

	//And define it´s deceleration.
	float deceleration=0.995f;

	float limit = 0.005f;
public:
	DeAccelerationComponent() {}
	void initComponent();
	void update();
	void render();
	virtual ~DeAccelerationComponent() {}
};
#endif

