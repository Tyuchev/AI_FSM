#pragma once
// Simulation.cpp

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Simulation.h"
#include "Location.h"



Simulation::Simulation()
{
	m_LocationHolder.reserve(9);
	for (int i = 0; i < 9; i++)
	{
		m_LocationHolder[i] = nullptr;
	}
}

Simulation::~Simulation()
{

}

void Simulation::initialiseMap()
{
	Location Forest{ "Forest", 0, 2 };
	addLocation(&Forest);
	Location Club{ "Club", 0, 1 };
	addLocation(&Club);
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

void Simulation::addLocation(Location* newLocation)
{
	if (newLocation != nullptr)
	{
		m_LocationHolder.push_back(std::make_shared<Location>(newLocation));
	}
}

void Simulation::addLocation(std::shared_ptr<Location> newLocation)
{
	if (newLocation != nullptr)
	{
		m_LocationHolder.push_back(newLocation);
	}
}