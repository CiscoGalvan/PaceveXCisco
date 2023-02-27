#include "FramedImage.h"

FramedImage::FramedImage(Texture* texture1)
{
	Component();
	texture = texture1;
	
}

void FramedImage::initComponent()
{
	tr = ent_->getComponent<Transform>(TRANSFORM_H);
}

void FramedImage::update()
{
	rect.x = tr->getPos().getX();
	rect.y = tr->getPos().getY();
	rect.h = tr->getH() / 5;
	rect.w = tr->getW() / 6;

	src.x = col * (tr->getW());
	src.y = fila *(tr->getH());
	src.h = tr->getH() ;
	src.w = tr->getW() ;
	

	if (col == 5 && cont>= 2)
	{
		col = 0;
		fila = (fila+1) % 5;
	}
	
	
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
