#pragma once
#include "GameState.h"
#include <stack>


class GameStateMachine
{
private:
    stack<GameState*> stackStates;
public:
    GameStateMachine() {};
    GameState* currentState();
    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();
    int stackLength();
};

