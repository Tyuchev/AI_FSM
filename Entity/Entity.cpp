#pragma once
// Entity.cpp

#include <iostream>
#include <string>

#include "Entity.h"



Entity::Entity()
{
	m_ID = nextID;
	nextID++;
}

Entity::~Entity()
{
}

int Entity::getID()
{
	return m_ID;
}

void Entity::setID(int inputID)
{
	m_ID = inputID;
}