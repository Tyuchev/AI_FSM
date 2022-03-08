#pragma once
// Location.h

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <cstdlib>



class Location
{

private:

	std::string m_LocationID;
	int m_XPos;
	int m_YPos;

	Location* m_North;
	Location* m_East;
	Location* m_South;
	Location* m_West;

public:

	Location() = delete;

	Location(std::string locationName, int x, int y);
	Location(std::string locationName, int x, int y, Location* north, Location* east, Location* south, Location* west);

	int findDistance(Location* goalLocation);

	std::string getLocID();
	int getX();
	int getY();
	Location* getNorth();
	Location* getEast();
	Location* getSouth();
	Location* getWest();

};