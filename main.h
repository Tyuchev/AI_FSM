#pragma once
// main.h

#include <iostream>
#include <string>
#include <chrono>

#include "Simulation/Simulation.h"
#include "Entity/Lumberjack.h"
#include "StateManager/StateManager.h"


int main();
void printData(StateManager<Lumberjack> x, StateManager<Lumberjack> y);