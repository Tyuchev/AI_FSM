#pragma once
// Resting.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Resting : public State
{

private:
	Resting();
	Resting(const Resting&);

public:

	~Resting();

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Resting* Instance();

};