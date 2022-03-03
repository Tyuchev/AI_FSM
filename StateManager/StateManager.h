#pragma once
// StateManager.h

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string>

#include "../State/State.h"


template <class entityType>
class StateManager
{

private:

	entityType* m_Owner;
	State<entityType>* m_CurrentState;
	State<entityType>* m_PreviousState;
	State<entityType>* m_GlobalState;


public:

	StateManager() = delete;
	StateManager(entityType* owner)
		:m_Owner(owner), m_CurrentState(0), m_PreviousState(0), m_GlobalState(0)
	{
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

	void Update()
	{
		if (m_GlobalState != nullptr)
		{
			m_GlobalState->Execute(m_Owner);
		}

		if (m_CurrentState != nullptr)
		{
			m_CurrentState->Execute(m_Owner);
		}
	}

	void ChangeState(State<entityType>* inputState)
	{
		assert(inputState != nullptr && "StateManager attempted to change to a NULL state");

		m_PreviousState = m_CurrentState;

		m_CurrentState->Exit(m_Owner);

		m_CurrentState = inputState;

		m_CurrentState->Enter(m_Owner);
	}

	void returnToPreviousState()
	{
		ChangeState(m_PreviousState);
	}

	bool isInState(State<entityType>& inputState) const
	{
		return m_CurrentState == inputState ? true : false;
	}



};