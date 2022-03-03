#pragma once
// Dancing.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Dancing : public State<Lumberjack>
{

private:
	Dancing() {};
	Dancing(const Dancing&);

public:

	virtual ~Dancing() {};

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Dancing* Instance();

};