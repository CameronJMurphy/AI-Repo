#pragma once
#include "Decision.h"
class IdleDecision : public Decision
{
public:

	virtual void makeDecision(Agent* agent, float deltaTime);
};

