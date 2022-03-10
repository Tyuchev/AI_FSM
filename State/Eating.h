#pragma once
// Eating.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"
#include "State.h"


class Eating : public State<Lumberjack>
{

private:
	Location* m_Location;

	Eating();
	Eating(const Eating&);

public:

	virtual ~Eating() {};

	Location* getLocation();
	void setLocation(Location* location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Eating* Instance();

};