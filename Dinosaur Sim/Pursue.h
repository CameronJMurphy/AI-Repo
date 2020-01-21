#pragma once
#include"Behaviour.h"
#include"Agent.h"

class PursueBehaviour : public Behaviour
{
public:
	PursueBehaviour();
	virtual ~PursueBehaviour();	
	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };
	void SetTarget(Agent* target) { m_target = target;}; //set the thing we are pursuing
private:
	Agent* m_target; // who are we pursuing
	float Speed = 40; // how fast we move to that point
	float weight = 1;
};

