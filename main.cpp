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

	//Telegrams for AI interactions

	// Render map?

	Simulation simulation;
	simulation.initialiseMap();

	std::shared_ptr<Location> bobStartLoc = (simulation.findLocation("Cabin"));
	std::shared_ptr<Location> fredStartLoc = (simulation.findLocation("Forest"));

	std::shared_ptr<Lumberjack> fred(new Lumberjack{ "fred", fredStartLoc});
	std::shared_ptr<Lumberjack> bob(new Lumberjack{ "bob", bobStartLoc});
	bob->updateCash(4); bob->updateHunger(-70); bob->updateThirst(-80);
	std::shared_ptr<Lumberjack> lillen(new Lumberjack{ "lillen", bobStartLoc});
	lillen->updateHappiness(-80);
	std::shared_ptr<Lumberjack> kisse(new Lumberjack{ "kisse", fredStartLoc});
	kisse->updateTiredness(-80); kisse->updateCash(3);


	simulation.m_EntityHolder.push_back(fred);
	simulation.m_EntityHolder.push_back(bob);
	simulation.m_EntityHolder.push_back(lillen);
	simulation.m_EntityHolder.push_back(kisse);

	StateManager<Lumberjack> bobManager{ &(*bob) };
	StateManager<Lumberjack> fredManager;
	fredManager.addEntity( &(*fred) );
	StateManager<Lumberjack> lillenManager{ &(*lillen) };
	StateManager<Lumberjack> kisseManager{ &(*kisse) };

	
	// Turn time calculation
	auto start = std::chrono::steady_clock::now();
	auto turnEnd = std::chrono::high_resolution_clock::now();
	auto elapsedNano = turnEnd - start;
	auto elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(elapsedNano);

	// Move these values into Simulation class?
	int turnLengthTime = 3;
	float turnTimeBuffer = 0.0f;
	int turnNum = 0;

	while (true)
	{
		start = std::chrono::high_resolution_clock::now();
		//Draw scene as often as poss
		std::cout << "?" << std::endl; // Replace with draw calls
		std::this_thread::sleep_for(std::chrono::seconds(1)); // Remove once simulation built out

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
				lillenManager.update();
				kisseManager.update();

				simulation.printData();
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


