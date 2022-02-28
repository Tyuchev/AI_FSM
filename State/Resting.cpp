#pragma once
// Resting.cpp

#include <iostream>
#include <string>

#include "Resting.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Resting::~Resting()
{
}

Resting* Resting::Instance()
{
	static Resting instance;

	return &instance;
}

void Resting::Enter(Lumberjack* lumberjack)
{
	if (true) //Lumberjack.location != home
	{
		//while ticks < 10
		std::cout << "Moving to my house" << std::endl;
		// Take 1 hour? Several ticks?? to move to house
		// ticks++
	}

	// Lumberjack->updateLocation(house)
}

void Resting::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateTiredness(7);
	std::cout << "Having a rest!" << std::endl;
}

void Resting::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " heading out to town" << std::endl;

	// Move back to market place
}