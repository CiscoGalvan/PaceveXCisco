#pragma once
#ifndef SHOWATOPPOSIDESIDE_H_
#define SHOWATOPPOSIDESIDE_H_
#include "../ecs/Component.h"
#include "Transform.h"
#include "../game/ecs.h"
class ShowAtOpposideSide : public Component
{

private:
	Transform* transform;
public:
	ShowAtOpposideSide(){}
	virtual ~ShowAtOpposideSide() {}

	void initComponent();
	void update();

};

#endif

