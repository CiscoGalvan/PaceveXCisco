#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include "src/utils/Vector2D.h"
#include "Component.h"
#include "src/sdlutils/SDLUtils.h"

class Transform : public Component {
private:
    Vector2D position, velocity;
    float width, height, rotation_;
public:
    Transform() {}
    // Constructora
    Transform(Vector2D pos, Vector2D vel, float w, float h, float r) : Component() {
        position = pos;
        velocity = vel;
        width = w;
        height = h;
        rotation_ = r;
    }

    // Destructora
    virtual ~Transform() { }
    // Devuelve su posicion
    inline Vector2D& getPos() { return position; }
    // Devuelve su velocidad
    inline Vector2D& getVel() { return velocity; }
    // Devuelve su ancho
    inline float getW() { return width; }
    // Devuelve su altura
    inline float getH() { return height; }
    // Devuelve su rotacion
    inline float getR() { return rotation_; }

    inline void setR(float valRot) { rotation_ = valRot; }

    inline void setH(float valHei) { height = valHei; }

    inline void setW(float valWid) { width = valWid; }

    inline void setPos(Vector2D Position) { position = Position; }

    inline void setVel(Vector2D Vel) { velocity = Vel; }

    void update();

    void render() {
        SDL_Rect rect = build_sdlrect(getPos(), getW(), getH());
        SDL_SetRenderDrawColor(sdlutils().renderer(), 255, 0, 255, 0);
        SDL_RenderDrawRect(sdlutils().renderer(), &rect);
        SDL_SetRenderDrawColor(sdlutils().renderer(), 0, 0, 0, 0);
    }
};
#endif

