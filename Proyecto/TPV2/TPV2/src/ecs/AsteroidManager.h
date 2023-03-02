#pragma once
#include "../sdlutils/Texture.h"
#include "Entity.h"
#include "../components/FramedImage.h"
#include "../components/Follow.h"
#include "../components/Transform.h"
#include "Manager.h"
#include "../components/ShowAtOpposideSide.h" 
#include "../components/Generations.h"

class Manager;
class AsteroidManager
{
private:
	Manager* mngr_;
	int nAsteroids = 0, timeGen = 5000;
	float lastRespawnTime = 0;
	bool respawn = false;
	Entity* asteroid;
public:
	AsteroidManager(Manager* manager) : mngr_(manager) {};
	~AsteroidManager();
	void createAsteroids(int n);
	inline void addAsteroidFrecuently() { createAsteroids(1); }
	inline int getTimeGen() { return timeGen; }
	inline float getLastRespawnTime() { return lastRespawnTime; }
	inline void setLastRespawnTime(float newValue) { lastRespawnTime = newValue; }
	inline bool getRespawn() { return respawn; }
	inline void setRespawn(bool newValue) { respawn = newValue; }


	
	inline int getNumAst() { return nAsteroids; }	
	inline void setNumAst(int newAsteroids) { nAsteroids = newAsteroids; }

	void destroyAllAsteroids();
	void onCollision(Entity* ent);
};

