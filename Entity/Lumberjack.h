#pragma once
// Lumberjack.h

#include <iostream>
#include <string>
#include <memory>

#include "Entity.h"
#include "../State/State.h"
#include "../StateManager/StateManager.h"


class Lumberjack : public Entity
{
private:

	std::unique_ptr<StateManager<Lumberjack>> m_StateManager;
	//Location location

	int m_Happiness;
	int m_Cash;
	int m_Deposits;
	int m_Hunger;
	int m_Thirst;
	int m_Tired;

	int m_MaxWood;
	int m_CurrentWood;



public:

	Lumberjack();
	~Lumberjack();

	void update();
	void updateState(State<Lumberjack>* inputState);

	void addLogToInventory();
	bool tractorFull();
	bool thirsty();
	bool hungry();
	bool tired();
	bool bored();

	void updateHappiness(int happinessChange);
	void updateCash(int cashChange);
	void updateDeposits(int depositsChange);
	void updateHunger(int hungerChange);
	void updateThirst(int thirstChange);
	void updateTiredness(int tirednessChange);

	int getHappiness();
	int getCash();
	int getDeposits();
	int getHunger();
	int getThirst();
	int getTiredness();

	int getCurrentWood();
	int getMaxWood();

};