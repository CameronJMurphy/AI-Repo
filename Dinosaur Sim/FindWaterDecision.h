#pragma once
#include "Decision.h"
class FindWaterDecision : public Decision
{
	FindWaterDecision(Agent* _target, float _speed) : m_target(_target), m_speed(_speed) {};
	virtual void makeDecision(Agent* agent, float deltaTime);


private:
	Agent* m_target;
	float m_speed;
};

