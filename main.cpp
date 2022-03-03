// main.cpp

#include <iostream>
#include <string>

#include "main.h"
#include "Simulation/Simulation.h"
#include "Entity/Entity.h"
#include "Entity/Lumberjack.h"
#include "StateManager/StateManager.h"


int main()
{

	std::cout << "Hello World" << std::endl;

	Lumberjack test;
	Lumberjack test2;

	test.update();
	test2.update();

	// Create a moving state? take start and end locations?

	return 0;
}