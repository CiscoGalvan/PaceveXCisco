#include "Game.h"

Game::Game() {
	// We first initialize SDL
	SDLUtils::init("Hola", WIN_WIDTH, WIN_HEIGHT, "resources/config/sdlutilsdemo.resources.json");
	renderer = SDLUtils::instance()->renderer();
	window = SDLUtils::instance()->window();

	stateMachine = new GameStateMachine();
	stateMachine->pushState(new MainMenuState(this));
}
Game::~Game() {
	stateMachine->~GameStateMachine();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit) {
		handleEvent();
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			refresh();
			startTime = SDL_GetTicks();
		}
		render();
	}

}
void Game::render()
{
	stateMachine->currentState()->render();
}
void Game::update()
{
	stateMachine->currentState()->update();
}
void Game::handleEvent()
{
	stateMachine->currentState()->handleEvents();
}

void Game::refresh()
{
	stateMachine->currentState()->refresh();
}



//Function to get the windows sizes
SDL_Rect Game::getWindowRect() {
	SDL_Rect destRect;
	destRect.h = WIN_HEIGHT;
	destRect.w = WIN_WIDTH;
	destRect.x = 0;
	destRect.y = 0;
	return destRect;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}

bool Game::getExit() {
	return exit;
}

void Game::setExit() {
	exit = !exit;
}

void Game::playFunction(Game* game) {
	/*delete game->stateMachine->currentState();*/
	game->stateMachine->changeState(new PlayState(game));
}

void Game::exitFunction(Game* game) {
	game->setExit();
}

void Game::pauseFunction(Game* game)
{
	game->stateMachine->pushState(new PauseState(game));
}
void Game::returnToGame(Game* game)
{
	//delete game->stateMachine->currentState();
	game->stateMachine->popState();
}
void Game::returnToMainMenu(Game* game)
{
	/*delete game->stateMachine->currentState();*/
	game->stateMachine->changeState(new MainMenuState(game));
}