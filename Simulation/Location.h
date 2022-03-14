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

	std::shared_ptr<Location> m_North;
	std::shared_ptr<Location> m_East;
	std::shared_ptr<Location> m_South;
	std::shared_ptr<Location> m_West;

public:

	Location() = delete;

	Location(std::string locationName, int x, int y);
	Location(std::string locationName, int x, int y, Location* north, Location* east, Location* south, Location* west);
	Location(std::string locationName, int x, int y, std::shared_ptr<Location> north, std::shared_ptr<Location> east, std::shared_ptr<Location> south, std::shared_ptr<Location> west);

	int findDistance(std::shared_ptr<Location> goalLocation);

	std::string getLocID();
	int getX();
	int getY();
	std::shared_ptr<Location> getNorth();
	std::shared_ptr<Location> getEast();
	std::shared_ptr<Location> getSouth();
	std::shared_ptr<Location> getWest();

	void setNorth(Location* newNorth);
	void setEast(Location* newEast);
	void setSouth(Location* newSouth);
	void setWest(Location* newWest);
	void setNorth(std::shared_ptr<Location> newNorth);
	void setEast(std::shared_ptr<Location> newEast);
	void setSouth(std::shared_ptr<Location> newSouth);
	void setWest(std::shared_ptr<Location> newWest);

};