#pragma once
#include "SDL.h"
#include "SDL_image.h"
//#include "checkML.h"
#include "src/sdlutils/Texture.h"
#include "src/utils/Vector2D.h"
#include <math.h>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "PauseState.h"
using namespace std;
using uint = unsigned int;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 5;
const uint FRAME_RATE = 10;

enum TextureName { Asteroid1, AsteroidGold1, Fighter1, Fire1, Heart1};

typedef struct
{
	string filename; // path to get the image
	uint hframes, vframes; // if the image is subdivided in various images this values are different than (1, 1)

}TextureDescription;


const TextureDescription TEXT_DESCRIPT[NUM_TEXTURES] =
{
	{"asteroid.png",6,5},{"asteroid_gold.png",6,5},{"fighter.png",1,1},{"fire.png",1,1},{"heart.png",1,1}
};

class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool exit = false; // control booleans
	Texture* textures[NUM_TEXTURES];
	GameStateMachine* stateMachine;
public:
	Game();
	~Game();
	void run();
	Texture* getTexture(TextureName name);				//update handleEvent, render
	SDL_Rect getWindowRect();
	void render();
	void update();
	void handleEvent();
	SDL_Renderer* getRenderer();
	void setExit();
	static void playFunction(Game* game);
	static void loadFunction(Game* game);
	static void exitFunction(Game* game);
	static void pauseFunction(Game* game);
	static void returnToGame(Game* game);
	static void returnToMainMenu(Game* game);
	static void saveFunction(Game* game) {};
	bool getExit();
};

