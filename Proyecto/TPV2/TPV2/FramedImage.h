#pragma once
#ifndef FRAMEDIMAGE_H_
#define FRAMEDIMAGE_H_
#include "Component.h"
#include "Transform.h"
#include "Image.h"
#include "Entity.h"
#include "src/sdlutils/SDLUtils.h"
class FramedImage : public Component
{
private:
	Transform* tr;
	Texture* texture;
	SDL_Rect rect,src;
	int fila = 0, col = 0, cont, widthFrame, heightFrame;

public:
	FramedImage(Texture* texture, int w, int h);
	void initComponent();
	void update();
	void render();


};

#endif