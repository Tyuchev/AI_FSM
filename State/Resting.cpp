#pragma once
// Resting.cpp

#include <iostream>
#include <string>

#include "Resting.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



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
		// Take 1 hour? Several ticks?? to move to house
		// ticks++
	}

	// Lumberjack->updateLocation(house)
}

void Resting::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateTiredness(15);

	if (lumberjack->getTiredness() >= 80)
	{
		lumberjack->m_IsTired = false;
	}
}

void Resting::Exit(Lumberjack* lumberjack)
{

}