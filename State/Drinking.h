#pragma once
// Drinking.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Drinking : public State<Lumberjack>
{

private:
	Drinking();
	Drinking(const Drinking&);

public:

	virtual ~Drinking();

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Drinking* Instance();

};