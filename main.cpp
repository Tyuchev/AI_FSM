// main.cpp

#include <iostream>
#include <string>
#include <chrono>
#include <thread>


#include "main.h"
#include "Simulation/Simulation.h"
#include "Entity/Lumberjack.h"
#include "StateManager/StateManager.h"


int main()
{

	std::cout << "Hello World" << std::endl;

	// Rework state class to take extra parameter for initial setup of entity
	//Allow for it to manage different types of entity

	// create all entities prior to use

	// INIT and draw map - Create links between nodes

	// rework print data func to an entity method



	Simulation simulation;
	simulation.initialiseMap();

	std::shared_ptr<Location> bobStart = std::make_shared<Location>(simulation.findLocation("Cabin"));
	std::shared_ptr<Location> fredStart = std::make_shared<Location>(simulation.findLocation("Forest"));

	Lumberjack bob{bobStart};
	Lumberjack fred{fredStart};

	StateManager<Lumberjack> bobManager{ &bob };
	StateManager<Lumberjack> fredManager;
	fredManager.addEntity(&fred);

	auto start = std::chrono::steady_clock::now();
	auto turnEnd = std::chrono::high_resolution_clock::now();
	auto elapsedNano = turnEnd - start;
	auto elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(elapsedNano);

	int turnLengthTime = 3;
	float turnTimeBuffer = 0.0f;
	int turnNum = 0;

	while (true)
	{
		//Draw scene as often as poss
		std::cout << "?" << std::endl;

		start = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		// if a 'turn' is 3 seconds, then update only values every 3 secs
		if (turnTimeBuffer > turnLengthTime)
		{

			std::cout << "Turn " << turnNum << std::endl;
			// if we are 'lagging behind'  we may have to update values several times per pass
			for (int i = 0; i < (turnTimeBuffer / turnLengthTime); i++)
			{
				turnTimeBuffer -= 3.0f;

				fredManager.update();
				bobManager.update();

				printData(bobManager, fredManager);
				turnNum++;
			}
		}

		turnEnd = std::chrono::high_resolution_clock::now();
		elapsedNano = turnEnd - start;
		elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(elapsedNano);
		turnTimeBuffer += elapsedSeconds.count();


	}



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