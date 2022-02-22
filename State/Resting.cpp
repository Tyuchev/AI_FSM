#pragma once
// Resting.cpp

#include <iostream>
#include <string>

#include "Resting.h"
#include "../Entity/Lumberjack.h"



Resting::~Resting()
{
}

Resting* Resting::Instance()
{
	static Resting instance;

	return &instance;
}