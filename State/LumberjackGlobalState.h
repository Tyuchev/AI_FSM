#pragma once
// LumberjackGlobalState.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class LumberjackGlobalState : public State<Lumberjack>
{

private:

	LumberjackGlobalState() {};
	LumberjackGlobalState(const LumberjackGlobalState&);


public:

	virtual ~LumberjackGlobalState() {};

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	void LumberjackStatCheck(Lumberjack* lumberjack);

	static LumberjackGlobalState* Instance();

};