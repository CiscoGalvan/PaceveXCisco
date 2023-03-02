#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "src/utils/checkML.h"
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
const uint FRAME_RATE = 10;

class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool exit = false; // control booleans
	//Texture* textures[NUM_TEXTURES];
	GameStateMachine* stateMachine;
public:
	Game();
	~Game();
	void run();
	SDL_Rect getWindowRect();
	void render();
	void update();
	void handleEvent();
	void refresh();
	SDL_Renderer* getRenderer();
	void setExit();
	static void playFunction(Game* game);
	static void exitFunction(Game* game);
	static void pauseFunction(Game* game);
	static void returnToGame(Game* game);
	static void returnToMainMenu(Game* game);
	static void saveFunction(Game* game) {};
	bool getExit();
};

