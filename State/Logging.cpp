#pragma once
// Logging.cpp

#include <iostream>
#include <string>

#include "Logging.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Logging* Logging::Instance()
{
	static Logging instance;

	return &instance;
}

void Logging::Enter(Lumberjack* lumberjack)
{
	if (true) //Lumberjack.location != forrest
	{
		//while ticks < 10
		std::cout << "Moving to the forrest" << std::endl;
		// Take 1 hour? Several ticks?? to move to forrest
		// ticks++
	}

	// Lumberjack->updateLocation(forrest)
}

void Logging::Execute(Lumberjack* lumberjack)
{
	lumberjack->addLogToInventory();
	std::cout << "Found a good tree to sell!" << std::endl;
}

void Logging::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " heading back to town" << std::endl;

	// Move back to market place
}