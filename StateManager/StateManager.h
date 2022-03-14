#pragma once
// StateManager.h

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string>

#include "../State/State.h"
#include "../State/Banking.h"
#include "../State/Dancing.h"
#include "../State/Drinking.h"
#include "../State/Eating.h"
#include "../State/Logging.h"
#include "../State/LumberjackGlobalState.h"
#include "../State/Resting.h"
#include "../State/Selling.h"
#include "../State/Travelling.h"


template <class entityType>
class StateManager
{

private:

	entityType* m_Entity;

	State<entityType>* m_CurrentState;
	State<entityType>* m_PreviousState;
	State<entityType>* m_GlobalState;


public:

	StateManager()
		:m_Entity(nullptr), m_CurrentState(nullptr), m_PreviousState(nullptr), m_GlobalState(nullptr)
	{
	}

	StateManager(entityType* entity)
		:m_Entity(entity)
	{
		setCurState(Resting::Instance());
		setGloState(LumberjackGlobalState::Instance());
		setPreState(nullptr);
	}


	void addEntity(entityType* entity)
	{
		m_Entity = entity;

		setCurState(Resting::Instance());
		setGloState(LumberjackGlobalState::Instance());
		setPreState(nullptr);
	}


	entityType* getEntity()
	{
		return m_Entity;
	}

	State<entityType>* getCurrentState() const
	{
		return m_CurrentState;
	}

	State<entityType>* getPreviousState()
	{
		return m_PreviousState;
	}

	State<entityType>* getGlobalState() const
	{
		return m_GlobalState;
	}

	void setCurState(State<entityType>* inputState)
	{
		m_CurrentState = inputState;
	}

	void setPreState(State<entityType>* inputState)
	{
		m_PreviousState = inputState;
	}

	void setGloState(State<entityType>* inputState)
	{
		m_GlobalState = inputState;
	}

	void update()
	{
		assert(m_Entity && "An Entity to be managed must be allocated before calling 'Update' on this StateManager ");
		if (m_GlobalState != nullptr)
		{
			m_GlobalState->Execute(m_Entity);
		}


		if (m_Entity->m_IsThirsty && m_Entity->getCash() > 0)
		{
			if (!isInState(Drinking::Instance()) && m_Entity->getLocation() != Drinking::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Drinking::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I'm thirsty, off to the pub!" << std::endl;
			}
			else if (!isInState(Drinking::Instance()))
			{
				changeState(Drinking::Instance());
				std::cout << "I'm thirsty, off to the pub!" << std::endl;
			}
			else
			{
				std::cout << "Still drowning my sorrows!" << std::endl;
			}
		}
		else if (m_Entity->m_IsHungry && m_Entity->getCash() > 0)
		{
			if (!isInState(Eating::Instance()) && m_Entity->getLocation() != Eating::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Eating::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I'm hungry, I'm going to the restaurant" << std::endl;
			}
			else if (!isInState(Eating::Instance()))
			{
				changeState(Eating::Instance());
				std::cout << "I'm hungry, I'm going to the restaurant" << std::endl;
			}
			else
			{
				std::cout << "Still eating!" << std::endl;
			}
		}
		else if (m_Entity->m_IsTired)
		{
			if (!isInState(Resting::Instance()) && m_Entity->getLocation() != Resting::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Resting::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I'm sleepy, I'm gonna get some rest" << std::endl;
			}
			else if (!isInState(Resting::Instance()))
			{
				changeState(Resting::Instance());
				std::cout << "I'm sleepy, I'm gonna get some rest" << std::endl;
			}
			else
			{
				std::cout << "*Snores*" << std::endl;
			}
		}
		else if (m_Entity->m_IsUnhappy && m_Entity->getCash() > 0)
		{
			if (!isInState(Dancing::Instance()) && m_Entity->getLocation() != Dancing::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Dancing::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "This is boring, time to bust a move!" << std::endl;
			}
			else if (!isInState(Dancing::Instance()))
			{
				changeState(Dancing::Instance());
				std::cout << "This is boring, time to bust a move!" << std::endl;
			}
			else
			{
				std::cout << "Still dancing!" << std::endl;
			}
		}
		else if (m_Entity->getCash() < 3 && m_Entity->getCurrentWood() > 0)
		{
			if (!isInState(Selling::Instance()) && m_Entity->getLocation() != Selling::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Selling::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "Wallet's feeling a bit light, I'd better sell some of these logs" << std::endl;
			}
			else if (!isInState(Selling::Instance()))
			{
				changeState(Selling::Instance());
				std::cout << "Wallet's feeling a bit light, I'd better sell some of these logs" << std::endl;
			}
			else
			{
				std::cout << "Still selling my wares" << std::endl;
			}
		}
		else if (m_Entity->getCash() < 3)
		{
			if (!isInState(Logging::Instance()) && m_Entity->getLocation() != Logging::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Logging::Instance()->getLocation());
				changeState(Logging::Instance());
				std::cout << "Wallet's feeling a bit light, I'd better go to work!" << std::endl;
			}
			else if (!isInState(Logging::Instance()))
			{
				changeState(Logging::Instance());
				std::cout << "Wallet's feeling a bit light, I'd better go to work!" << std::endl;
			}
			else
			{
				std::cout << "Continuing to work in the forest" << std::endl;
			}
		}
		else if (m_Entity->m_TractorFull)
		{
			if (!isInState(Selling::Instance()) && m_Entity->getLocation() != Selling::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Selling::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "Tractor's full, better head back to market" << std::endl;
			}
			else if (!isInState(Selling::Instance()))
			{
				changeState(Selling::Instance());
				std::cout << "Tractor's full, better head back to market" << std::endl;
			}
			else
			{
				std::cout << "Still selling my wares" << std::endl;
			}
		}
		else if (m_Entity->getCash() >= 10)
		{
			if (!isInState(Banking::Instance()) && m_Entity->getLocation() != Banking::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Banking::Instance()->getLocation());
				changeState(Banking::Instance());
				std::cout << "It's been a good harvest, lets add to my savings" << std::endl;
			}
			if (!isInState(Banking::Instance()))
			{
				changeState(Banking::Instance());
				std::cout << "It's been a good harvest, lets add to my savings" << std::endl;
			}
			else
			{
				std::cout << "Taking a while in the bank...!" << std::endl;
			}
		}
		else if (m_Entity->getCurrentWood() < m_Entity->getMaxWood())
		{
			if (!isInState(Logging::Instance()) && m_Entity->getLocation() != Logging::Instance()->getLocation())
			{
				m_Entity->updateTargetLoc(Logging::Instance()->getLocation());
				changeState(Logging::Instance());
				std::cout << "Got nothin' else todo, might as well get back to work" << std::endl;
			}
			else if (!isInState(Logging::Instance()))
			{
				changeState(Logging::Instance());
				std::cout << "Got nothin' else todo, might as well get back to work" << std::endl;
			}
			else
			{
				std::cout << "Continuing to work in the forest" << std::endl;
			}
		}


		if (m_CurrentState != nullptr)
		{
			m_CurrentState->Execute(m_Entity);
		}
	}

	void changeState(State<entityType>* inputState)
	{
		assert(m_Entity && "An Entity to be managed must be allocated before calling 'ChangeState' on this StateManager ");
		assert(inputState && "StateManager attempted to change to a NULL state");

		m_PreviousState = m_CurrentState;

		m_CurrentState->Exit(m_Entity);

		m_CurrentState = inputState;

		m_CurrentState->Enter(m_Entity);
	}

	void returnToPreviousState()
	{
		changeState(m_PreviousState);
	}

	bool isInState(State<entityType>* inputState) const
	{
		return m_CurrentState == inputState ? true : false;
	}



};