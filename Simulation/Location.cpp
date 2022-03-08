#pragma once
// Location.cpp

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
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

std::string Location::getLocID()
{
	return m_LocationID;
}

int Location::getX()
{
	return m_XPos;
}

int Location::getY() 
{
	return m_YPos;
}

Location* Location::getNorth()
{
	return m_North;
}

Location* Location::getEast()
{
	return m_East;
}

Location* Location::getSouth()
{
	return m_South;
}

Location* Location::getWest()
{
	return m_West;
}

int Location::findDistance(Location* location)
{
	int distance;
	if (location == nullptr)
	{
		assert(false && "Cannot findDistance to a null location");
	}
	else
	{
		return distance = abs(m_XPos - location->m_XPos) + abs(m_YPos - location->m_YPos);
	}
}
