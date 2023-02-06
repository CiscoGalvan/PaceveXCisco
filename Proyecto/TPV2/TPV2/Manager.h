#pragma once
#include "ecs.h"
using namespace ecs;
class Entity;
class Manager
{
	public:
		Manager();
		virtual ~Manager();
		Entity* addEntity();
		void refresh();
		void update();
		void render();
	private:
		vector<Entity*> ents_;
};

