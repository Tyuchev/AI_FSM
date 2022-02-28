#pragma once
// Lumberjack.cpp

#include <iostream>
#include <string>
#include <memory>

#include "Lumberjack.h"
#include "Entity.h"
#include "../State/State.h"
#include "../StateManager/StateManager.h"

//Possible Lumberjack states
#include "../State/Banking.h"
#include "../State/Dancing.h"
#include "../State/Drinking.h"
#include "../State/Eating.h"
#include "../State/Logging.h"
#include "../State/Resting.h"
#include "../State/LumberjackGlobalState.h"


Lumberjack::Lumberjack()
	:m_Happiness(100), m_Cash(2), m_Deposits(0), m_Hunger(100), m_Thirst(100), m_Tired(100)
{
	m_StateManager = std::make_unique<StateManager<Lumberjack>>(this);
	m_StateManager->setCurState(Resting::Instance());
	m_StateManager->setGloState(LumberjackGlobalState::Instance());
	m_StateManager->setPreState(nullptr);

	Entity::setID(nextID);
	nextID++;
}

Lumberjack::~Lumberjack()
{

}

void Lumberjack::update()
{
	m_StateManager->Update();
}

int Lumberjack::getCash()
{
	return m_Cash;
}

int Lumberjack::getDeposits()
{
	return m_Deposits;
}

int Lumberjack::getHunger()
{
	return m_Hunger;
}

int Lumberjack::getThirst()
{
	return m_Thirst;
}

int Lumberjack::getTiredness()
{
	return m_Tired;
}

void Lumberjack::updateState(State<Lumberjack>* inputState)
{
	m_StateManager->ChangeState(inputState);
}

void Lumberjack::addLogToInventory()
{
	m_currentLogs++;
}

void Lumberjack::updateHappiness(int happinessChange)
{
	m_Happiness += happinessChange;
}

void Lumberjack::updateCash(int cashChange)
{
	m_Cash += cashChange;
}

void Lumberjack::updateDeposits(int depositsChange)
{
	m_Deposits += depositsChange;
}
void Lumberjack::updateHunger(int hungerChange)
{
	m_Hunger += hungerChange;
}

void Lumberjack::updateThirst(int thirstChange)
{
	m_Thirst += thirstChange;
}
void Lumberjack::updateTiredness(int tirednessChange)
{
	m_Tired += tirednessChange;
}

int Lumberjack::getHappiness()
{
	return m_Happiness;
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

int Lumberjack::getCurrentWood()
{
	return m_MaxWood;
}

int Lumberjack::getMaxWood()
{
	return m_MaxWood;
}