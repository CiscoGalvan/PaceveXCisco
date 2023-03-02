#include "Health.h"
#include "../game/Game.h"
Health::Health(int maxLifes_,Game* game_)
{
	maxLives = maxLifes_;
	lives = maxLifes_;
	game = game_;
	texture = &SDLUtils::instance()->images().at("heart");
}

void Health::render()
{
	for (int i = 0; i < lives; i++)
	{
		Vector2D pos = Vector2D(55*i+5, 10);

		SDL_Rect destRect = build_sdlrect(pos, 50, 50);

		texture->render(destRect);

	}
}