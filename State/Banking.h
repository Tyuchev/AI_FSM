#pragma once
// Banking.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"
#include "State.h"


class Banking : public State<Lumberjack>
{

private:
	std::shared_ptr<Location> m_Location;

	Banking();
	Banking(const Banking&);

public:

	virtual ~Banking() {};

	std::shared_ptr<Location> getLocation();
	void setLocation(std::shared_ptr<Location> location);

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Banking* Instance();

};