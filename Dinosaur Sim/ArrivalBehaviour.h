#pragma once
#include"Behaviour.h"
#include"Agent.h"
class ArrivalBehaviour : public Behaviour
{
public:
	ArrivalBehaviour();
	virtual ~ArrivalBehaviour();
	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };
	void SetRadius(float num) { targetsRadius = num; };
	void SetTarget(Agent* target) { m_target = target; };

private:
	float targetsRadius = 20;
	Agent* m_target;
	float speed = 40;
	float weight = 1;
};

