// main.cpp

#include <iostream>
#include <string>
#include <chrono>


#include "main.h"
#include "Simulation/Simulation.h"
#include "Entity/Lumberjack.h"
#include "StateManager/StateManager.h"


int main()
{

	std::cout << "Hello World" << std::endl;

	Lumberjack bob;
	Lumberjack fred;

	StateManager<Lumberjack> bobManager{ &bob };
	StateManager<Lumberjack> fredManager;
	fredManager.addEntity(&fred);

	auto start = std::chrono::high_resolution_clock::now();
	auto turnEnd = std::chrono::high_resolution_clock::now();
	auto elapsedTime = start - turnEnd;

	while (true)
	{
		//Draw scene as often as poss
		start = std::chrono::high_resolution_clock::now();
		elapsedTime = start - turnEnd;

		// if a 'turn' is 3 seconds, then update only values every 3 secs
		if (elapsedTime.count() > 3)
		{
			fredManager.update();
			bobManager.update();

			printData(bobManager, fredManager);

			turnEnd = std::chrono::high_resolution_clock::now();
		}

	}



	// Create a moving state? take start and end locations?

	// create all entities prior to use

	// INIT and draw map - Create links between nodes

	return 0;
}

void printData(StateManager<Lumberjack> x, StateManager<Lumberjack> y)
{
	std::cout << "Bob's stats, " << "Happiness: " << x.getEntity()->getHappiness() << ", Cash: " << x.getEntity()->getCash() << ", Deposits: " << x.getEntity()->getDeposits() <<
		", Thirst: " << x.getEntity()->getThirst() << ", Hunger: " << x.getEntity()->getHunger() << " , Fatigue: " << x.getEntity()->getTiredness() 
		<< ", Wood: " << x.getEntity()->getCurrentWood() << std::endl;

	std::cout << "Fred's stats, " << "Happiness: " << y.getEntity()->getHappiness() << ", Cash: " << y.getEntity()->getCash() << ", Deposits: " << y.getEntity()->getDeposits() <<
		", Thirst: " << y.getEntity()->getThirst() << ", Hunger: " << y.getEntity()->getHunger() << " , Fatigue: " << y.getEntity()->getTiredness()
		<< ", Wood: " << y.getEntity()->getCurrentWood() << std::endl;
	std::cout << std::endl;
}