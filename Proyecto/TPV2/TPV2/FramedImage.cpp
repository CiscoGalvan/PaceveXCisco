#include "FramedImage.h"

FramedImage::FramedImage(Texture* texture1, int w, int h) : Component()
{
	texture = texture1;
	widthFrame = w;
	heightFrame = h;
	
}

void FramedImage::initComponent()
{
	tr = ent_->getComponent<Transform>(TRANSFORM_H);
}

void FramedImage::update()
{
	rect.x = tr->getPos().getX();
	rect.y = tr->getPos().getY();
	rect.h = tr->getH();
	rect.w = tr->getW();

	src.x = col * (widthFrame);
	src.y = fila * (heightFrame);
	src.h = heightFrame;
	src.w = widthFrame;
	

	//This if will be used to change the row to render
	if (col == 5 && cont>= 2)
	{
		col = 0;
		fila = (fila+1) % 5;
	}
	
	
	//We change the col
	if (cont >= 5)
	{
		col++;
		cont = 0;
	}
	cont++;
}

void FramedImage::render()
{
	texture->render(src, rect, 0, nullptr);
}
