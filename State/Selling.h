#pragma once
// Selling.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Selling : public State<Lumberjack>
{

private:
	Selling() {};
	Selling(const Selling&);

public:

	~Selling() {};

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Selling* Instance();


};