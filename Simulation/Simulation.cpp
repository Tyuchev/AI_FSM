#pragma once
// Simulation.cpp

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Simulation.h"
#include "Location.h"
#include"../Entity/Lumberjack.h"
#include "../StateManager/StateManager.h"



Simulation::Simulation()
	:m_LocationHolder(9, nullptr), m_LocationHolderSize(0)
{
}

Simulation::~Simulation()
{

}

std::vector<std::shared_ptr<Lumberjack>> Simulation::getEntityHolder()
{
	return m_EntityHolder;
}

void Simulation::initialiseMap()
{
	std::shared_ptr<Location> Forest(new Location{"Forest", 0, 2 });
	std::shared_ptr<Location> Club(new Location{ "Club", 0, 1 });
	std::shared_ptr<Location> Pub(new Location{ "Pub", 0, 0 });
	std::shared_ptr<Location> Cafe(new Location{ "Cafe", 1, 0 });
	std::shared_ptr<Location> Market(new Location{ "Market", 1, 1 });
	std::shared_ptr<Location> Bank(new Location{ "Bank", 2, 1 });
	std::shared_ptr<Location> Cabin(new Location{ "Cabin", 2, 0 });

	Forest->setSouth(Club);
	Club->setNorth(Forest);
	Club->setEast(Market);
	Club->setSouth(Pub);
	Pub->setNorth(Club);
	Pub->setEast(Cafe);

	Market->setEast(Bank);
	Market->setSouth(Cafe);
	Market->setWest(Club);
	Cafe->setNorth(Market);
	Cafe->setEast(Cabin);
	Cafe->setWest(Pub);

	Bank->setSouth(Cabin);
	Bank->setWest(Market);
	Cabin->setNorth(Bank);
	Cabin->setWest(Cafe);


	addLocation(Forest);
	addLocation(Club);
	addLocation(Pub);
	addLocation(Cafe);
	addLocation(Market);
	addLocation(Bank);
	addLocation(Cabin);

	Logging::Instance()->setLocation(findLocation("Forest"));
	Dancing::Instance()->setLocation(findLocation("Club"));
	Drinking::Instance()->setLocation(findLocation("Pub"));
	Eating::Instance()->setLocation(findLocation("Cafe"));
	Selling::Instance()->setLocation(findLocation("Market"));
	Banking::Instance()->setLocation(findLocation("Bank"));
	Resting::Instance()->setLocation(findLocation("Cabin"));
	
}


std::shared_ptr<Location> Simulation::findLocation(std::string locationID)
{
	for (int i = 0; i < m_LocationHolder.size(); i++)
	{
		if (m_LocationHolder[i] != nullptr)
		{
			if (m_LocationHolder[i]->getLocID() == locationID)
			{
				return m_LocationHolder[i];
			}
		}
	}

	assert(false && "A location with this string ID does not exist");
	//if LocID not found
	return nullptr;
}

void Simulation::addLocation(Location& newLocation)
{
	m_LocationHolder[m_LocationHolderSize] = std::make_shared<Location>(newLocation);
	m_LocationHolderSize++;
}

void Simulation::addLocation(std::shared_ptr<Location> newLocation)
{
	if (newLocation != nullptr)
	{
		m_LocationHolder[m_LocationHolderSize] = newLocation;
		m_LocationHolderSize++;
	}
}

void Simulation::printData()
{
	for (int i = 0; i < m_EntityHolder.size(); i++)
	{
		std::cout << m_EntityHolder[i]->m_Name;
		std::cout << "'s stats: " << "Happiness: " << m_EntityHolder[i]->getHappiness() << ", Cash: " << m_EntityHolder[i]->getCash() << ", Deposits: " << m_EntityHolder[i]->getDeposits() <<
			", Thirst: " << m_EntityHolder[i]->getThirst() << ", Hunger: " << m_EntityHolder[i]->getHunger() << " , Fatigue: " << m_EntityHolder[i]->getTiredness()
			<< ", Wood: " << m_EntityHolder[i]->getCurrentWood() << std::endl;
	}

	std::cout << std::endl;
}