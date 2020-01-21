#pragma once
#include "Behaviour.h"
#include <vector.h>
#include "Agent.h"
class SeekBehaviour : public Behaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();
	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };
	void SetTarget(Agent* agent) { m_target = agent; }
private:
	Agent* m_target;
	float seekSpeed = 20;
	float weight = 1;
};

