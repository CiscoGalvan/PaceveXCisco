#pragma once
#include "Manager.h"
#include <stack>


class GameStateMachine
{
private:
    stack<Manager*> stackStates;
public:
    GameStateMachine() {};
    Manager* currentState();
    void pushState(Manager* state);
    void changeState(Manager* state);
    void popState();
    int stackLength();
};

