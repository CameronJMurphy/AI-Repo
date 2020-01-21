#pragma once
#include "Behaviour.h"
#include "SeekBehaviour.h"
#include <vector.h>
#include<cmath>

class WanderBehaviour : public Behaviour, SeekBehaviour
{
public:
	WanderBehaviour();
	virtual ~WanderBehaviour();

	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };

	void setAngle(vector2& vec, float value);

protected:
	float radius = 5000;
	float distanceToSphere = 1;
	float jitter = 20;
	float angleChange = 50;
	float speed = 500;
	float weight = 1;
};

