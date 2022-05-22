#pragma once
// Simulation.cpp

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Simulation.h"
#include "Location.h"



Simulation::Simulation()
	:m_LocationHolder(9, nullptr), m_LocationHolderSize(0)
{
}

Simulation::~Simulation()
{

}

void Simulation::initialiseMap()
{
	Location Forest{ "Forest", 0, 2 };
	Location Club{ "Club", 0, 1 };
	Location Pub{ "Pub", 0, 0 };
	Location Cafe{ "Cafe", 1, 0 };
	Location Market{ "Market", 1, 1 };
	Location Bank{ "Bank", 2, 1 };
	Location Cabin{ "Cabin", 2, 0 };

	Forest.setSouth(Club);
	Club.setNorth(Forest);
	Club.setEast(Market);
	Club.setSouth(Pub);
	Pub.setNorth(Club);
	Pub.setEast(Cafe);

	Market.setEast(Bank);
	Market.setSouth(Cafe);
	Market.setWest(Club);
	Cafe.setNorth(Market);
	Cafe.setEast(Cabin);
	Cafe.setWest(Pub);

	Bank.setSouth(Cabin);
	Bank.setWest(Market);
	Cabin.setNorth(Bank);
	Cabin.setWest(Cafe);

	//Attach locations to states
	//Allow character to change the default location for a state to a prefered option

	addLocation(Forest);
	addLocation(Club);
	addLocation(Pub);
	addLocation(Cafe);
	addLocation(Market);
	addLocation(Bank);
	addLocation(Cabin);
	
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