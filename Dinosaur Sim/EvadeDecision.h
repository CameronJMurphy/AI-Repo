#pragma once
#include "Decision.h"
class EvadeDecision : public Decision
{
public:
	EvadeDecision(Agent* target) : m_target(target) {};
	virtual void makeDecision(Agent* agent, float deltaTime);
private:
	Agent* m_target = nullptr;
	float fleeSpeed = 40;	
};

