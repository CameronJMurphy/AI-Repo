#pragma once
#include <vector.h>


class Agent;

class Behaviour //interface
{
public:
	// empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}
	// pure virtual function for executing the behaviour
	virtual vector2 Update(Agent* agent, float deltaTime) = 0;
	virtual float GetWeight() = 0;
};

