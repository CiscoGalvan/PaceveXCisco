#pragma once
#pragma once
#ifndef IMAGE_H
#define IMAGE_H_
#include "../sdlutils/Texture.h"
#include "Transform.h" 
#include "../ecs/Entity.h"
class Image : public Component {
private:
	Transform* tr_; // Consulta las caracteristicas fisicas
	Texture* tex_;	// Imagen a rederizar
	SDL_RendererFlip s = SDL_FLIP_NONE;
public:
	// Constructora
	Image(Texture* tex) : tr_(nullptr), tex_(tex) {}
	// Destructora
	virtual ~Image() { }
	// Inicializa el componente
	void initComponent() {
		tr_ = ent_->getComponent<Transform>(int(TRANSFORM_H));
		assert(tr_ != nullptr);
	}

	void update() {}

	// Dibuja en escena
	void render() {
		//Cuando la imagen solo tiene un frame (sin animación)
		SDL_Rect dest = build_sdlrect(tr_->getPos(), tr_->getW(), tr_->getH());
		tex_->render(dest, tr_->getR());
	}
};
#endif