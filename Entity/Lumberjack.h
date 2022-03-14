#pragma once
// Lumberjack.h

#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>

#include "Entity.h"
#include "../Simulation/Location.h"



class Lumberjack : public Entity
{
private:

	std::shared_ptr<Location> m_Location;
	std::shared_ptr<Location> m_TargetLoc;

	int m_Happiness;
	int m_Cash;
	int m_Deposits;
	int m_Hunger;
	int m_Thirst;
	int m_Tired;

	int m_MaxWood;
	int m_CurrentWood;



public:

	Lumberjack() = delete;
	Lumberjack(std::shared_ptr<Location> location);

	bool m_IsUnhappy;
	bool m_IsHungry;
	bool m_IsThirsty;
	bool m_IsTired;
	bool m_TractorFull;

	void update();

	void addLogToInventory();
	void removeLogInventory();
	bool tractorFull();
	bool thirsty();
	bool hungry();
	bool tired();
	bool bored();

	void updateTargetLoc(std::shared_ptr<Location> newLocation);
	void updateLocation(std::shared_ptr<Location> newLocation);
	void updateHappiness(int happinessChange);
	void updateCash(int cashChange);
	void updateDeposits(int depositsChange);
	void updateHunger(int hungerChange);
	void updateThirst(int thirstChange);
	void updateTiredness(int tirednessChange);

	void depositEarnings();

	std::shared_ptr<Location> getLocation();
	std::shared_ptr<Location> getTargetLoc();
	int getHappiness();
	int getCash();
	int getDeposits();
	int getHunger();
	int getThirst();
	int getTiredness();

	int getCurrentWood();
	int getMaxWood();


};