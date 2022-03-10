#pragma once
// Dancing.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"
#include "State.h"


class Dancing : public State<Lumberjack>
{

private:
	Location* m_Location;

	Dancing();
	Dancing(const Dancing&);

public:

	virtual ~Dancing() {};

	Location* getLocation();
	void setLocation(Location* location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Dancing* Instance();

};