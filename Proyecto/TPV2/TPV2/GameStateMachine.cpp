#include "GameStateMachine.h"


Manager* GameStateMachine::currentState()
{
	return stackStates.top();
}

void GameStateMachine::changeState(Manager* state)
{
	popState();
	pushState(state);
}

void GameStateMachine::pushState(Manager* state)
{
	stackStates.push(state);
}

void GameStateMachine::popState()
{
	stackStates.pop();
}

int GameStateMachine::stackLength() {
	return stackStates.size();
}