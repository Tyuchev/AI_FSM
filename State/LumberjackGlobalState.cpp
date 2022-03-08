#pragma once
// LumberjackGlobalState.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "LumberjackGlobalState.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



LumberjackGlobalState* LumberjackGlobalState::Instance()
{
	static LumberjackGlobalState instance;

	return &instance;
}

void LumberjackGlobalState::Enter(Lumberjack* lumberjack)
{
	std::cout << "AI " << lumberjack->getID() << " entering lumberjack global state" << std::endl;
}

void LumberjackGlobalState::Execute(Lumberjack* lumberjack)
{
	lumberjack->updateHappiness(-1);
	lumberjack->updateHunger(-2);
	lumberjack->updateThirst(-3);
	lumberjack->updateTiredness(-2);

	// Checks if Lumberjack should die or warning flags need to be set
	LumberjackStatCheck(lumberjack);

}

void LumberjackGlobalState::LumberjackStatCheck(Lumberjack* lumberjack)
{
	if (lumberjack->getHappiness() < 1 ||
		lumberjack->getHunger() < 1 ||
		lumberjack->getThirst() < 1 ||
		lumberjack->getTiredness() < 1)
	{
		std::cout << std::endl;
		std::cout << "This AI has fallen into disrepair" << std::endl;
		std::cout << std::endl;
		assert(false);
		// Send delete message to simulation
	}

	// Lumberjack stat warning checks
	if (lumberjack->thirsty())
	{
		lumberjack->m_IsThirsty = true;
	}
	else if (lumberjack->hungry())
	{
		lumberjack->m_IsHungry = true;
	}
	else if (lumberjack->tired())
	{
		lumberjack->m_IsTired = true;
	}
	else if (lumberjack->bored())
	{
		lumberjack->m_IsUnhappy = true;
	}

}

void LumberjackGlobalState::Exit(Lumberjack* lumberjack)
{

}