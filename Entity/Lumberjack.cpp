#pragma once
// Lumberjack.cpp

#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <assert.h>

#include "Lumberjack.h"
#include "Entity.h"



Lumberjack::Lumberjack()
	:m_Location(nullptr), m_Happiness(100), m_Cash(2), m_Deposits(0), m_Hunger(100), m_Thirst(100), m_Tired(100), m_CurrentWood(0), m_MaxWood(10),
	m_IsUnhappy(false), m_IsThirsty(false), m_IsHungry(false), m_IsTired(false), m_TractorFull(false)
{
	Entity::setID(nextID);
	nextID++;
}


void Lumberjack::update()
{
	std::cout << "Is this necessary?" << std::endl;
}

Location* Lumberjack::getLocation()
{
	return m_Location;
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

int Lumberjack::getHappiness()
{
	return m_Happiness;
}

void Lumberjack::addLogToInventory()
{
	m_CurrentWood++;
}
void Lumberjack::removeLogInventory()
{
	m_CurrentWood--;
}

void Lumberjack::updateLocation(Location* newLocation)
{
	m_Location = newLocation;
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

void Lumberjack::depositEarnings()
{
	assert(m_Cash >= 3);

	m_Deposits += (m_Cash - 3);
	m_Cash = 3;

}

bool Lumberjack::tractorFull()
{
	if (m_CurrentWood == m_MaxWood)
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
	return m_CurrentWood;
}

int Lumberjack::getMaxWood()
{
	return m_MaxWood;
}