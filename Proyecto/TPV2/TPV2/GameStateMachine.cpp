#include "GameStateMachine.h"
GameStateMachine::~GameStateMachine() // destructora
{
	clearState();
	clearState();
}


Manager* GameStateMachine::currentState()
{
	return stackStates.top();
}

void GameStateMachine::changeState(Manager* state)
{
	
		popState();
		pushState(state);
	
	
}
void GameStateMachine::clearState()
{

	while (!stackToDelete.empty())
	{
		delete(stackToDelete.top());
		stackToDelete.pop();
	}
}

void GameStateMachine::pushState(Manager* state)
{
	stackStates.push(state);
}

void GameStateMachine::popState()
{
	if (!stackStates.empty())
	{
		stackToDelete.push(stackStates.top());
		stackStates.pop();
	}
}

int GameStateMachine::stackLength() {
	return stackStates.size();
}