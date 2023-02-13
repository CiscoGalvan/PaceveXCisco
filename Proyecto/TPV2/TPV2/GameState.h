#pragma once
#include <list>
#include "Entity.h"
using namespace std;

class GameState
{
protected:
    list<Entity*> entities;
public:
    virtual ~GameState() {};
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void handleEvents() = 0;
};
