#pragma once
// Simulation.h

#include <iostream>
#include <string>
#include <vector>

#include "Location.h"


class Simulation
{

private:

	std::vector<Location*> m_LocationHolder;

	void initialiseMap();

public:

	Simulation();
	~Simulation();

	Location* getLocation(std::string locationID);
	void addLocation(Location* newLocation);



};
