#pragma once
// Logging.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Logging.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"



Logging::Logging()
	:m_Location(nullptr)
{

}


std::shared_ptr<Location> Logging::getLocation()
{
	return m_Location;
}

void Logging::setLocation(std::shared_ptr<Location> location)
{
	m_Location = location;
}

Logging* Logging::Instance()
{
	static Logging instance;

	return &instance;
}

void Logging::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");
	if (true) //Lumberjack.location != forrest
	{
		//while ticks < 10
		// Take 1 hour? Several ticks?? to move to forrest
		// ticks++
	}

	// Lumberjack->updateLocation(forrest)
}

void Logging::Execute(Lumberjack* lumberjack)
{
	lumberjack->addLogToInventory();
}

void Logging::Exit(Lumberjack* lumberjack)
{


}