#pragma once
// Banking.cpp

#include <iostream>
#include <string>

#include "Banking.h"
#include "../Entity/Lumberjack.h"
#include "State.h"



Banking::~Banking()
{
}

Banking* Banking::Instance()
{
	static Banking instance;

	return &instance;
}