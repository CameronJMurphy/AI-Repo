#pragma once
#include "Behaviour.h"


class Condition : public Behaviour
{
public:
	//virtual function for other conditions to override
	Condition() {}
	virtual ~Condition() {}
	virtual bool test(Agent* gameObject) const = 0;

	virtual bool execute(Agent* gameObject, float deltaTime)
	{
		if (test(gameObject))
		{
			return true;
		}
		return false;
	}

};

