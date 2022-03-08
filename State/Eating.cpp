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
		// Take 1 hour? Several ticks?? to move to house
		// ticks++
	}

	lumberjack->updateCash(-1);
	// Lumberjack->updateLocation(cafe)
}

void Eating::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHunger(20);

	if (lumberjack->getHunger() >= 80)
	{
		lumberjack->m_IsHungry = false;
	}
}

void Eating::Exit(Lumberjack* lumberjack)
{

}