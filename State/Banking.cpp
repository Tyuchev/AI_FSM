#pragma once
// Banking.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Banking.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"



Banking::Banking()
	:m_Location(nullptr)
{

}


Location* Banking::getLocation()
{
	return m_Location;
}

void Banking::setLocation(Location* location)
{
	m_Location = location;
}

Banking* Banking::Instance()
{
	static Banking instance;

	return &instance;
}

void Banking::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");
	assert(lumberjack->getCash() >= 3 && "Cash cannot be deposited if the entity has less that 3 m_Cash");

	if (true) //Lumberjack.location != home
	{
		//while ticks < 10
		// Take 1 hour? Several ticks?? to move to bank
		// ticks++
	}

	// Lumberjack->updateLocation(bank)
}

void Banking::Execute(Lumberjack* lumberjack)
{
	lumberjack->depositEarnings();
}

void Banking::Exit(Lumberjack* lumberjack)
{

}