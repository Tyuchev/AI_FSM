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

		std::cout << m_Entity->m_Name << ": ";

		if (m_Entity->m_IsThirsty && m_Entity->getCash() > 0)
		{
			if (!isInState(Drinking::Instance()) && !m_Entity->getLocation()->compareLoc((Drinking::Instance()->getLocation())))
			{
				m_Entity->updateTargetLoc(Drinking::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I'm thirsty, walking to the pub!" << std::endl;
			}
			else if (!isInState(Drinking::Instance()))
			{
				changeState(Drinking::Instance());
				std::cout << "I'm thirsty, good thing im already at the pub!" << std::endl;
			}
			else
			{
				std::cout << "Still drowning my sorrows!" << std::endl;
			}
		}
		else if (m_Entity->m_IsHungry && m_Entity->getCash() > 0)
		{
			if (!isInState(Eating::Instance()) && !m_Entity->getLocation()->compareLoc(Eating::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Eating::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I'm hungry, walking to the cafe" << std::endl;
			}
			else if (!isInState(Eating::Instance()))
			{
				changeState(Eating::Instance());
				std::cout << "I'm hungry, im at the cafe" << std::endl;
			}
			else
			{
				std::cout << "Still eating!" << std::endl;
			}
		}
		else if (m_Entity->m_IsTired)
		{
			if (!isInState(Resting::Instance()) && !m_Entity->getLocation()->compareLoc(Resting::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Resting::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I'm sleepy, walking home" << std::endl;
			}
			else if (!isInState(Resting::Instance()))
			{
				changeState(Resting::Instance());
				std::cout << "I'm sleepy, getting in bed" << std::endl;
			}
			else
			{
				std::cout << "*Snores*" << std::endl;
			}
		}
		else if (m_Entity->m_IsUnhappy && m_Entity->getCash() > 0)
		{
			if (!isInState(Dancing::Instance()) && !m_Entity->getLocation()->compareLoc(Dancing::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Dancing::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "This is boring, walking to the Club!" << std::endl;
			}
			else if (!isInState(Dancing::Instance()))
			{
				changeState(Dancing::Instance());
				std::cout << "Time to bust a move!" << std::endl;
			}
			else
			{
				std::cout << "Still dancing!" << std::endl;
			}
		}
		else if (m_Entity->getCash() < 3 && m_Entity->getCurrentWood() > 0)
		{
			if (!isInState(Selling::Instance()) && !m_Entity->getLocation()->compareLoc(Selling::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Selling::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "Wallet's feeling a bit light, heading to market to sell my goods" << std::endl;
			}
			else if (!isInState(Selling::Instance()))
			{
				changeState(Selling::Instance());
				std::cout << "In the market selling my items" << std::endl;
			}
			else
			{
				std::cout << "Still selling my wares" << std::endl;
			}
		}
		else if (m_Entity->getCash() < 3)
		{
			if (!isInState(Logging::Instance()) && !m_Entity->getLocation()->compareLoc(Logging::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Logging::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "I need some cash, walking to work!" << std::endl;
			}
			else if (!isInState(Logging::Instance()))
			{
				changeState(Logging::Instance());
				std::cout << "At work, starting now!" << std::endl;
			}
			else
			{
				std::cout << "Continuing to work" << std::endl;
			}
		}
		else if (m_Entity->m_TractorFull)
		{
			if (!isInState(Selling::Instance()) && !m_Entity->getLocation()->compareLoc(Selling::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Selling::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "Tractor's full, better walk back to market" << std::endl;
			}
			else if (!isInState(Selling::Instance()))
			{
				changeState(Selling::Instance());
				std::cout << "Arrived at the market, selling wares" << std::endl;
			}
			else
			{
				std::cout << "Still selling my wares" << std::endl;
			}
		}
		else if (m_Entity->getCash() >= 10)
		{
			if (!isInState(Banking::Instance()) && !m_Entity->getLocation()->compareLoc(Banking::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Banking::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "Lets add to my savings, walking to the bank" << std::endl;
			}
			if (!isInState(Banking::Instance()))
			{
				changeState(Banking::Instance());
				std::cout << "At the bank, lets add to my savings" << std::endl;
			}
			else
			{
				std::cout << "Taking a while in the bank...!" << std::endl;
			}
		}
		else if (m_Entity->getCurrentWood() < m_Entity->getMaxWood())
		{
			if (!isInState(Logging::Instance()) && !m_Entity->getLocation()->compareLoc(Logging::Instance()->getLocation()))
			{
				m_Entity->updateTargetLoc(Logging::Instance()->getLocation());
				changeState(Travelling::Instance());
				std::cout << "Got nothin' else todo, walking back to work" << std::endl;
			}
			else if (!isInState(Logging::Instance()))
			{
				changeState(Logging::Instance());
				std::cout << "At work, starting now!" << std::endl;
			}
			else
			{
				std::cout << "Continuing to work" << std::endl;
			}
		}
		std::cout << std::endl;

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