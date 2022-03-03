#pragma once
// Dancing.cpp

#include <iostream>
#include <string>

#include "Dancing.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Dancing* Dancing::Instance()
{
	static Dancing instance;

	return &instance;
}

void Dancing::Enter(Lumberjack* lumberjack)
{
	if (true) //Lumberjack.location != club
	{
		//while ticks < 10
		std::cout << "Moving to the club" << std::endl;
		// Take 1 hour? Several ticks?? to move to club
		// ticks++
	}

	// Lumberjack->updateLocation(club)
}

void Dancing::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHappiness(30);
	std::cout << "Party all night!" << std::endl;
}

void Dancing::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " all partied out!" << std::endl;

	// Move back to market place
}