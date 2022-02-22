#pragma once
// State.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"


class State
{

private:

	State();
	State(const State&);


public:

	virtual ~State();

	virtual void Enter(Lumberjack* lumberjack) = 0;
	virtual void Execute(Lumberjack* lumberjack) = 0;
	virtual void Exit(Lumberjack* lumberjack) = 0;

};
