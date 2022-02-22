#pragma once
// Logging.cpp

#include <iostream>
#include <string>

#include "Logging.h"
#include "../Entity/Lumberjack.h"



Logging::~Logging()
{
}

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

	if (lumberjack->thirsty())
	{
		std::cout << "I'm thirsty, off to the pub!" << std::endl;
		//change lumberjack state to drinking and location to pub
	}
	else if (lumberjack->hungry())
	{
		std::cout << "I'm hungry, I'm going to the restaurant" << std::endl;
		//change lumberjack state to eating at restaurant location
	}
	else if (lumberjack->tired())
	{
		std::cout << "I'm sleepy, I'm gonna get some rest" << std::endl;
		//change lumberjack state to resting - location home or market
	}
	else if (lumberjack->bored())
	{
		std::cout << "This is boring, time to bust a move!" << std::endl;
		//change lumberjack state to dancing and location to night club
	}
	else if (lumberjack->tractorFull())
	{
		std::cout << "Tractor's full, better head back to market" << std::endl;
		//change lumberjack state to return to market
	}

}

void Logging::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " heading back to town" << std::endl;
}