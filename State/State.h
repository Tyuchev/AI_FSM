#pragma once
// State.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"


template <class entityType>
class State
{

private:

	State();
	State(const State&);


public:

	virtual ~State();

	virtual void Enter(entityType* lumberjack) = 0;
	virtual void Execute(entityType* lumberjack) = 0;
	virtual void Exit(entityType* lumberjack) = 0;

};
