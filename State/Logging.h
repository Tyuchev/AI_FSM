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
	std::shared_ptr<Location> m_Location;

	Logging();
	Logging(const Logging&);


public:

	virtual ~Logging() {};

	std::shared_ptr<Location> getLocation();
	void setLocation(std::shared_ptr<Location> location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Logging* Instance();

};