#pragma once
// Logging.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Logging : public State<Lumberjack>
{

private:

	Logging() {};
	Logging(const Logging&);


public:

	virtual ~Logging() {};

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Logging* Instance();

};