#pragma once
// Simulation.cpp

#include <iostream>
#include <string>

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
	//create and link locations
}

Location* Simulation::getLocation(std::string locationID)
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
		m_LocationHolder.push_back(newLocation);
	}
}