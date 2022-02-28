#pragma once
// Banking.h

#include <iostream>
#include <string>

#include "../Entity/Lumberjack.h"
#include "State.h"


class Banking : public State<Lumberjack>
{

private:
	Banking();
	Banking(const Banking&);

public:

	virtual ~Banking();

	virtual void Enter(Lumberjack* lumberjack);
	virtual void Execute(Lumberjack* lumberjack);
	virtual void Exit(Lumberjack* lumberjack);

	static Banking* Instance();

};