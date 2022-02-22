#pragma once
// Entity.h

#include <iostream>
#include <string>

class Entity
{
private:

	int m_ID;


public:

	Entity();
	virtual ~Entity();

	int getID();
	void setID(int inputID);
	virtual void update() = 0;


};

static int nextID;