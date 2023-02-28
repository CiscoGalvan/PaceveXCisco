#pragma once
#include "src/sdlutils/SDLNetUtils.h"
#include "src/sdlutils/Texture.h"
#include "Entity.h"
#include "FramedImage.h"
#include "Follow.h"
#include "Transform.h"
#include "Manager.h"
#include "ShowAtOpposideSide.h" 

class Manager;
class AsteroidManager
{
private:
	Manager* mngr_;
	int nAsteroids = 0;
	Entity* asteroid;
public:
	AsteroidManager(Manager* manager) : mngr_(manager) {};
	void createAsteroids(int n);

};

