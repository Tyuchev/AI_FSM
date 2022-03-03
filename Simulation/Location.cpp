#pragma once
// Location.cpp

#include <iostream>
#include <string>
#include <cstdlib>

#include "Location.h"



Location::Location(std::string locationName, int x, int y)
	: m_LocationID(locationName), m_XPos(x), m_YPos(y), m_North(nullptr), m_East(nullptr), m_South(nullptr), m_West(nullptr)
{
}

Location::Location(std::string locationName, int x, int y, Location* north, Location* east, Location* south, Location* west)
	: m_LocationID(locationName), m_XPos(x), m_YPos(y), m_North(north), m_East(east), m_South(south), m_West(west)
{
}


int Location::findDistance(Location* location)
{
	int distance;

	return distance = abs(m_XPos - location->m_XPos) + abs(m_YPos - location->m_YPos);
}
