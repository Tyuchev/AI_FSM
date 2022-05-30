#pragma once
// Drinking.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Drinking.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"



Drinking::Drinking()
	:m_Location(nullptr)
{

}


std::shared_ptr<Location> Drinking::getLocation()
{
	return m_Location;
}

void Drinking::setLocation(std::shared_ptr<Location> location)
{
	m_Location = location;
}

Drinking* Drinking::Instance()
{
	static Drinking instance;

	return &instance;
}

void Drinking::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");

	lumberjack->updateCash(-1);
}

void Drinking::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateThirst(35);

	if (lumberjack->getThirst() >= 80)
	{
		lumberjack->m_IsThirsty = false;
	}
}

void Drinking::Exit(Lumberjack* lumberjack)
{

}