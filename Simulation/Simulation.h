#pragma once
// Simulation.h

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Location.h"
#include "../Entity/Lumberjack.h"
#include "../StateManager/StateManager.h"


class Simulation
{

private:

	std::vector<std::shared_ptr<Location>> m_LocationHolder;
	int m_LocationHolderSize;

public:
	
	Simulation();
	~Simulation();

	std::vector<std::shared_ptr<Lumberjack>> m_EntityHolder;

	std::vector<std::shared_ptr<Lumberjack>> getEntityHolder();

	std::shared_ptr<Location> findLocation(std::string locationID);

	void initialiseMap();
	void addLocation(Location& newLocation);
	void addLocation(std::shared_ptr<Location> newLocation);
	void printData();

};
