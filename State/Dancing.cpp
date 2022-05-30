#pragma once
// Dancing.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Dancing.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"



Dancing::Dancing()
	:m_Location(nullptr)
{

}


std::shared_ptr<Location> Dancing::getLocation()
{
	return m_Location;
}

void Dancing::setLocation(std::shared_ptr<Location> location)
{
	m_Location = location;
}

Dancing* Dancing::Instance()
{
	static Dancing instance;

	return &instance;
}

void Dancing::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");

	lumberjack->updateCash(-1);
}

void Dancing::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHappiness(35);

	if (lumberjack->getHappiness() >= 80)
	{
		lumberjack->m_IsUnhappy = false;
	}

}

void Dancing::Exit(Lumberjack* lumberjack)
{

}