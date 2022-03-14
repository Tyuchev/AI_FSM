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
	if (true) //Lumberjack.location != home
	{
		//while ticks < 10
		// Take 1 hour? Several ticks?? to move to house
		// ticks++
	}

	// Lumberjack->updateLocation(house)
}

void Resting::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateTiredness(15);

	if (lumberjack->getTiredness() >= 80)
	{
		lumberjack->m_IsTired = false;
	}
}

void Resting::Exit(Lumberjack* lumberjack)
{

}