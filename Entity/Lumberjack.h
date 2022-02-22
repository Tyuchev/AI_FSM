#pragma once
// Lumberjack.h

#include <iostream>
#include <string>

#include "Entity.h"
#include "../State/State.h"


class Lumberjack : public Entity
{
private:

	State* m_currentState;
	//Location location

	int m_Happiness;
	int m_Cash;
	int m_Deposits;
	int m_Hunger;
	int m_Thirst;
	int m_Tired;

	int m_maxLogs;
	int m_currentLogs;



public:

	Lumberjack();
	~Lumberjack();

	void update();
	void updateState(State* inputState);

	void addLogToInventory();
	bool tractorFull();
	bool thirsty();
	bool hungry();
	bool tired();
	bool bored();


};