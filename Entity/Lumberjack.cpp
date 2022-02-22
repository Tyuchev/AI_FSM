#pragma once
// Lumberjack.cpp

#include <iostream>
#include <string>

#include "Lumberjack.h"
#include "Entity.h"
#include "../State/State.h"


Lumberjack::Lumberjack()
	:m_Happiness(100), m_Cash(2), m_Deposits(0), m_Hunger(100), m_Thirst(100), m_Tired(100)
{
	Entity::setID(nextID);
	nextID++;
}

Lumberjack::~Lumberjack()
{

}

void Lumberjack::update()
{
	m_Happiness -= 1;
	m_Hunger -= 2;
	m_Thirst -= 3;
	m_Tired -= 2;

	if (m_currentState != nullptr)
	{
		m_currentState->Execute(this);
	}

	if (m_Happiness < 1 || 
		m_Hunger < 1 || 
		m_Thirst < 1 || 
		m_Tired < 1)
	{
		std::cout << std::endl;
		std::cout << "This AI has fallen into disrepair" << std::endl;
		std::cout << std::endl;

		// Send delete message to simulation
	}


	std::cout << "Entity " << this->getID() <<  " Updated :)" << std::endl;
}

void Lumberjack::updateState(State* inputState)
{
	if (m_currentState != nullptr && inputState != nullptr)
	{
		m_currentState->Exit(this);
		m_currentState = inputState;
		inputState->Enter(this);
	}

	// call execute method
}

void Lumberjack::addLogToInventory()
{
	m_currentLogs++;
}

bool Lumberjack::tractorFull()
{
	if (m_currentLogs == m_maxLogs)
	{
		return true;
	}

	return false;
}

bool Lumberjack::thirsty()
{
	if (m_Thirst <= 40)
	{
		return true;
	}

	return false;
}

bool Lumberjack::hungry()
{
	if (m_Hunger <= 30)
	{
		return true;
	}

	return false;
}

bool Lumberjack::tired()
{
	if (m_Tired <= 20)
	{
		return true;
	}

	return false;
}

bool Lumberjack::bored()
{
	if (m_Happiness <= 30)
	{
		return true;
	}

	return false;
}