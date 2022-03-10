#pragma once
// Drinking.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"
#include "State.h"


class Drinking : public State<Lumberjack>
{

private:
	Location* m_Location;

	Drinking();
	Drinking(const Drinking&) {};

public:

	virtual ~Drinking() {};

	Location* getLocation();
	void setLocation(Location* location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Drinking* Instance();

};