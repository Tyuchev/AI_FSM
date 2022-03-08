#pragma once
// Travelling.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "../Simulation/Location.h"
#include "State.h"


class Travelling : public State<Lumberjack>
{

private:
	Travelling() {};
	Travelling(const Travelling&);

public:

	~Travelling() {};

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack, Location* goal);
	virtual void Exit(Lumberjack* lumberjack);

	static Travelling* Instance();


};