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
	std::shared_ptr<Location> m_Location;

	Dancing();
	Dancing(const Dancing&);

public:

	virtual ~Dancing() {};

	std::shared_ptr<Location> getLocation();
	void setLocation(std::shared_ptr<Location> location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Dancing* Instance();

};