#pragma once
// LumberjackGlobalState.cpp

#include <iostream>
#include <string>

#include "LumberjackGlobalState.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



LumberjackGlobalState::~LumberjackGlobalState()
{
}

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

	// Checks if Lumberjack should die
	LumberjackStatCheck(lumberjack);

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
	else if (lumberjack->getCurrentWood() < lumberjack->getMaxWood())
	{
		std::cout << "Got nothin' else todo, might as well get back to work" << std::endl;
		//change lumberjack state to return to market -> then set to Logging
	}


	std::cout << "Entity " << lumberjack->getID() << " Updated :)" << std::endl;
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

		// Send delete message to simulation
	}
}

void LumberjackGlobalState::Exit(Lumberjack* lumberjack)
{
	std::cout << "Entity " << lumberjack->getID() << " heading back to town" << std::endl;

	// Move back to market place
}