#pragma once
#ifndef SHOWATOPPOSIDESIDE_H_
#define SHOWATOPPOSIDESIDE_H_
#include "Component.h"
#include "Transform.h"
#include "ecs.h"
class ShowAtOpposideSide : public Component
{

private:
	Transform* transformShip;
public:
	ShowAtOpposideSide(){}
	virtual ~ShowAtOpposideSide() {}

	void initComponent();
	void update();

};

#endif

