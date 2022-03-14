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

Location::Location(std::string locationName, int x, int y, std::shared_ptr<Location> north, std::shared_ptr<Location> east, std::shared_ptr<Location> south, std::shared_ptr<Location> west)
	: m_LocationID(locationName), m_XPos(x), m_YPos(y), m_North(north), m_East(east), m_South(south), m_West(west)
{
}

Location::Location(std::string locationName, int x, int y, Location* north, Location* east, Location* south, Location* west)
	: m_LocationID(locationName), m_XPos(x), m_YPos(y)
{
	m_North = std::make_shared<Location>(north);
	m_East = std::make_shared<Location>(east);
	m_South = std::make_shared<Location>(south);
	m_West = std::make_shared<Location>(west);
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

std::shared_ptr<Location>Location::getNorth()
{
	return m_North;
}

std::shared_ptr<Location> Location::getEast()
{
	return m_East;
}

std::shared_ptr<Location> Location::getSouth()
{
	return m_South;
}

std::shared_ptr<Location> Location::getWest()
{
	return m_West;
}

void Location::setNorth(std::shared_ptr<Location> newNorth)
{
	m_North = newNorth;
}

void Location::setEast(std::shared_ptr<Location> newEast)
{
	m_East = newEast;
}

void Location::setSouth(std::shared_ptr<Location> newSouth)
{
	m_South = newSouth;
}

void Location::setWest(std::shared_ptr<Location> newWest)
{
	m_West = newWest;
}


void Location::setNorth(Location* newNorth)
{
	m_North = std::make_shared<Location>(newNorth);
}

void Location::setEast(Location* newEast)
{
	m_East = std::make_shared<Location>(newEast);
}

void Location::setSouth(Location* newSouth)
{
	m_South = std::make_shared<Location>(newSouth);
}

void Location::setWest(Location* newWest)
{
	m_West = std::make_shared<Location>(newWest);
}


int Location::findDistance(std::shared_ptr<Location> location)
{
	int distance;
	if (location == nullptr)
	{
		assert(false && "Cannot findDistance to a null location");
		return 0;
	}
	else
	{
		return distance = abs(m_XPos - location->m_XPos) + abs(m_YPos - location->m_YPos);
	}
}
