#pragma once
#include "Decision.h"
class AttackDecision : public Decision
{
public:
	AttackDecision(Agent* _target) {}
	virtual void makeDecision(Agent* agent, float deltaTime);
	

private:

};

