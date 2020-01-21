#pragma once
#include "Behaviour.h"
#include <vector.h>
#include "Input.h"
#include "Agent.h"


class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };

private :
	float weight = 1;
};

