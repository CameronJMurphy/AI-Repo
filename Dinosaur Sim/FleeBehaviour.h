#pragma once
#include "Behaviour.h"
#include <vector.h>
#include "Agent.h"
class FleeBehaviour : public Behaviour
{
public:
	FleeBehaviour();
	virtual ~FleeBehaviour();
	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };
	void SetTarget(Agent* agent) { m_target = agent; }
protected:
	Agent* m_target;
	float fleeSpeed = 20;
	float weight = 2;
};

