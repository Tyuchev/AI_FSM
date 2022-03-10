#pragma once
// Selling.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Selling.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"


Selling::Selling()
	:m_Location(nullptr)
{

}


Location* Selling::getLocation()
{
	return m_Location;
}

void Selling::setLocation(Location* location)
{
	m_Location = location;
}

Selling* Selling::Instance()
{
	static Selling instance;

	return &instance;
}

void Selling::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");
	if (true) //Lumberjack.location != market
	{
		//while ticks < 10
		// Take 1 hour? Several ticks?? to move to market
		// ticks++
	}

	// Lumberjack->updateLocation(market)
}

void Selling::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateCash(1);
	lumberjack->removeLogInventory();

	if (lumberjack->getCurrentWood() < 1)
	{
		lumberjack->m_TractorFull = false;
	}
}

void Selling::Exit(Lumberjack* lumberjack)
{

}