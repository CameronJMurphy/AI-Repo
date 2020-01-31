#pragma once
#include "Agent.h"
//base class
class Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};

