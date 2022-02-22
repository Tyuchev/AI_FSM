#pragma once
// Lumberjack.h

#include <iostream>
#include <string>

#include "Entity.h"


class Lumberjack : public Entity
{
private:

	//State* to a state
	//Location location

	int m_Cash;
	int m_Deposits;
	int m_Hunger;
	int m_Thirst;
	int m_Tired;



public:

	Lumberjack();
	~Lumberjack();

	void update();
	void updateState();


};