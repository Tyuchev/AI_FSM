#pragma once
// Logging.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"
#include "State.h"


class Logging : public State<Lumberjack>
{

private:
	Location* m_Location;

	Logging();
	Logging(const Logging&);


public:

	virtual ~Logging() {};

	Location* getLocation();
	void setLocation(Location* location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Logging* Instance();

};