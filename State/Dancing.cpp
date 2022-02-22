#pragma once
// Dancing.cpp

#include <iostream>
#include <string>

#include "Dancing.h"
#include "../Entity/Lumberjack.h"



Dancing::~Dancing()
{
}

Dancing* Dancing::Instance()
{
	static Dancing instance;

	return &instance;
}