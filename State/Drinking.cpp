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
		// Take 1 hour? Several ticks?? to move to pub
		// ticks++
	}

	// Lumberjack->updateLocation(pub)
}

void Drinking::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateThirst(30);

	if (lumberjack->getThirst() >= 80)
	{
		lumberjack->m_IsThirsty = false;
	}
}

void Drinking::Exit(Lumberjack* lumberjack)
{

}