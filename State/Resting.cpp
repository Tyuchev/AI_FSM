#pragma once
// Resting.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Resting.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"


Resting::Resting()
	:m_Location(nullptr)
{

}


std::shared_ptr<Location> Resting::getLocation()
{
	return m_Location;
}

void Resting::setLocation(std::shared_ptr<Location> location)
{
	m_Location = location;
}

Resting* Resting::Instance()
{
	static Resting instance;

	return &instance;
}

void Resting::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");
}

void Resting::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateTiredness(18);

	if (lumberjack->getTiredness() >= 80)
	{
		lumberjack->m_IsTired = false;
	}
}

void Resting::Exit(Lumberjack* lumberjack)
{

}