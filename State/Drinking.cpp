#pragma once
// Drinking.cpp

#include <iostream>
#include <string>

#include "Drinking.h"
#include "../Entity/Lumberjack.h"



Drinking::~Drinking()
{
}

Drinking* Drinking::Instance()
{
	static Drinking instance;

	return &instance;
}