#pragma once
// Eating.cpp

#include <iostream>
#include <string>

#include "Eating.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Eating* Eating::Instance()
{
	static Eating instance;

	return &instance;
}

void Eating::Enter(Lumberjack* lumberjack)
{
	if (true) //Lumberjack.location != cafe
	{
		//while ticks < 10
		std::cout << "Moving to the cafe" << std::endl;
		// Take 1 hour? Several ticks?? to move to house
		// ticks++
	}

	// Lumberjack->updateLocation(cafe)
}

void Eating::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHunger(20);
	std::cout << "Having a snack!" << std::endl;
}

void Eating::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " is full and is heading out to town" << std::endl;

	//Move back to market place
}