#pragma once
// Location.h

#include <iostream>
#include <string>



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



};