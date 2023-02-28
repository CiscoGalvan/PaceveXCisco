#pragma once
#ifndef GENERATIONS_H_
#define GENERATIONS_H_
#include "Component.h"

class Generations : public Component
{
private:
	int generations;

public:
	Generations(int GenInicial) : Component(), generations(GenInicial) {};
	inline int getGenerations() { return generations; }
	inline void setGenerations(int newGen) { generations = newGen; }
};

#endif
