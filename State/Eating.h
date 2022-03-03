#pragma once
// Eating.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Eating : public State<Lumberjack>
{

private:
	Eating() {};
	Eating(const Eating&);

public:

	virtual ~Eating() {};

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Eating* Instance();

};