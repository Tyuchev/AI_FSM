#pragma once
// Drinking.cpp

#include <iostream>
#include <string>

#include "Drinking.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Drinking* Drinking::Instance()
{
	static Drinking instance;

	return &instance;
}

void Drinking::Enter(Lumberjack* lumberjack)
{
	if (true) //Lumberjack.location != pub
	{
		//while ticks < 10
		std::cout << "Moving to the pub" << std::endl;
		// Take 1 hour? Several ticks?? to move to pub
		// ticks++
	}

	// Lumberjack->updateLocation(pub)
}

void Drinking::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateThirst(30);
	std::cout << "Enjoying a fresh cold one!" << std::endl;

	if (lumberjack->getThirst() >= 80)
	{
		lumberjack->m_IsThirsty = false;
	}
}

void Drinking::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " refreshed and heading out to town" << std::endl;

	 // Move back to market place
}