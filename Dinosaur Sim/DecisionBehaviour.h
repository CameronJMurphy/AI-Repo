#pragma once
#include "Behaviour.h"
#include "Decision.h"
class DecisionBehaviour : public Behaviour
{
public:
	virtual vector2 Update(Agent* agent, float deltaTime) //each frame update your decision
	{
		m_decision->makeDecision(agent, deltaTime);
		return vector2(0, 0);
	}

	virtual float GetWeight() { return 0; }

	void addDecision(Decision* d) //adds 1 decision which is at the top of the decision tree
	{
		m_decision = d;
	};

private:
	Decision* m_decision;
};

