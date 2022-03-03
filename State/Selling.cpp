#pragma once
// Selling.cpp

#include <iostream>
#include <string>

#include "Selling.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Selling* Selling::Instance()
{
	static Selling instance;

	return &instance;
}

void Selling::Enter(Lumberjack* lumberjack)
{
	if (true) //Lumberjack.location != market
	{
		//while ticks < 10
		std::cout << "Moving to the market" << std::endl;
		// Take 1 hour? Several ticks?? to move to market
		// ticks++
	}

	// Lumberjack->updateLocation(market)
}

void Selling::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateCash(1);
	lumberjack->removeLogInventory();
	std::cout << "Made a sale!" << std::endl;
}

void Selling::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " made a profit!" << std::endl;

}