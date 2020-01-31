#pragma once
#include "Decision.h"
class WanderDecision : public Decision
{
public:

	virtual void makeDecision(Agent* agent, float deltaTime);

	void setAngle(vector2& vec, float value);

private:
	float radius = 10;
	float distanceToSphere = 400;
	float jitter = 1;
	float angleChange = 1;
	float speed = 20;
};

