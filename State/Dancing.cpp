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
		// Take 1 hour? Several ticks?? to move to club
		// ticks++
	}

	lumberjack->updateCash(-1);
	// Lumberjack->updateLocation(club)
}

void Dancing::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHappiness(30);

	if (lumberjack->getHappiness() >= 80)
	{
		lumberjack->m_IsUnhappy = false;
	}

}

void Dancing::Exit(Lumberjack* lumberjack)
{

}