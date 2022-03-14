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
	std::shared_ptr<Location> m_Location;

	Drinking();
	Drinking(const Drinking&):m_Location(nullptr) {};

public:

	virtual ~Drinking() {};

	std::shared_ptr<Location> getLocation();
	void setLocation(std::shared_ptr<Location> location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Drinking* Instance();

};