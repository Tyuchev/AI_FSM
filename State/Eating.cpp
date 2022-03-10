#pragma once
// Eating.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Eating.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"



Eating::Eating()
	:m_Location(nullptr)
{

}


Location* Eating::getLocation()
{
	return m_Location;
}

void Eating::setLocation(Location* location)
{
	m_Location = location;
}

Eating* Eating::Instance()
{
	static Eating instance;

	return &instance;
}

void Eating::Enter(Lumberjack* lumberjack)
{
	assert(m_Location != nullptr && "Cannot enter state which does not have a location set");
	if (true) //Lumberjack.location != cafe
	{
		//while ticks < 10
		// Take 1 hour? Several ticks?? to move to house
		// ticks++
	}

	lumberjack->updateCash(-1);
	// Lumberjack->updateLocation(cafe)
}

void Eating::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHunger(20);

	if (lumberjack->getHunger() >= 80)
	{
		lumberjack->m_IsHungry = false;
	}
}

void Eating::Exit(Lumberjack* lumberjack)
{

}