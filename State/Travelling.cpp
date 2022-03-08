#pragma once
// Travelling.cpp

#include <iostream>
#include <string>

#include "Travelling.h"
#include "../Entity/Lumberjack.h"
#include "../Simulation/Location.h"
#include "State.h"



Travelling* Travelling::Instance()
{
	static Travelling instance;

	return &instance;
}

void Travelling::Enter(Lumberjack* lumberjack)
{

}

void Travelling::Execute(Lumberjack* lumberjack, Location* goal)
{
	Location* currentLocation = lumberjack->getLocation();
	if (currentLocation == goal)
	{
		std::cout << "You are already at your location!!!!" << std::endl;
		return;
	}

	int xDiff = goal->getX() - currentLocation->getX();
	int yDiff = goal->getY() - currentLocation->getY();

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

void Travelling::Execute(Lumberjack* lumberjack)
{
	std::cout << "Wrong Execute method" << std::endl;
}