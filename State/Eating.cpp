#pragma once
// Eating.cpp

#include <iostream>
#include <string>

#include "Eating.h"
#include "../Entity/Lumberjack.h"



Eating::~Eating()
{
}

Eating* Eating::Instance()
{
	static Eating instance;

	return &instance;
}