#pragma once
// Simulation.h

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Location.h"


class Simulation
{

private:

	std::vector<std::shared_ptr<Location>> m_LocationHolder;

public:

	Simulation();
	~Simulation();

	void initialiseMap();

	std::shared_ptr<Location> findLocation(std::string locationID);
	void addLocation(Location* newLocation);
	void addLocation(std::shared_ptr<Location> newLocation);


};
