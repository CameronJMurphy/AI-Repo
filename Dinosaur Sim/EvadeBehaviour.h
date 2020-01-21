#pragma once
#include"Behaviour.h"
#include"Agent.h"
class EvadeBehaviour : public Behaviour
{
public:
	EvadeBehaviour();
	virtual ~EvadeBehaviour();
	virtual vector2 Update(Agent* agent, float deltaTime); 
	virtual float GetWeight() { return weight; };
	void SetTarget(Agent* agent) { m_target = agent; }
private:
	Agent* m_target;
	float fleeSpeed = 40;
	float weight = 2;
};

