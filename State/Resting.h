#pragma once
// Resting.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"
#include "State.h"


class Resting : public State<Lumberjack>
{

private:
	Location* m_Location;

	Resting();
	Resting(const Resting&);

public:

	~Resting() {};

	Location* getLocation();
	void setLocation(Location* location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Resting* Instance();

};