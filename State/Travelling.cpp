#pragma once
// Travelling.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Travelling.h"
#include "State.h"
#include "../Simulation/Location.h"
#include "../Entity/Lumberjack.h"


Travelling* Travelling::Instance()
{
	static Travelling instance;

	return &instance;
}

void Travelling::Enter(Lumberjack* lumberjack)
{

}

void Travelling::Execute(Lumberjack* lumberjack)
{
	std::shared_ptr<Location> currentLocation = lumberjack->getLocation();
	if (currentLocation == lumberjack->getTargetLoc())
	{
		assert(false && "ERROR: Entity is already at target location!");
	}

	int xDiff = lumberjack->getTargetLoc()->getX() - currentLocation->getX();
	int yDiff = lumberjack->getTargetLoc()->getY() - currentLocation->getY();

	if (xDiff > 0 && currentLocation->getEast() != nullptr)
	{
		lumberjack->updateLocation(currentLocation->getEast());
	}
	else if (xDiff < 0 && currentLocation->getWest() != nullptr)
	{
		lumberjack->updateLocation(currentLocation->getWest());
	}
	else if (yDiff > 0 && currentLocation->getNorth() != nullptr)
	{
		lumberjack->updateLocation(currentLocation->getNorth());
	}
	else if (yDiff < 0 && currentLocation->getSouth() != nullptr)
	{
		lumberjack->updateLocation(currentLocation->getSouth());
	}

	return;
}

void Travelling::Exit(Lumberjack* lumberjack)
{

}