#pragma once
// Lumberjack.cpp

#include <iostream>
#include <string>

#include "Lumberjack.h"


Lumberjack::Lumberjack()
	:m_Cash(2), m_Deposits(0), m_Hunger(100), m_Thirst(100), m_Tired(100)
{
	setID(nextID);
	nextID++;
}

Lumberjack::~Lumberjack()
{

}

void Lumberjack::update()
{
	std::cout << "Entity " << this->getID() <<  " Updated :)" << std::endl;
}

void Lumberjack::updateState()
{
	// Update State pointer here

	// if (m_State != nullptr)
	// call execute method
}