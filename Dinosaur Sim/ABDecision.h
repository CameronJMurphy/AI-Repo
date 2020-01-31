#pragma once
#include"Decision.h"
#include"Condition.h"
//a decision tree node
class ABDecision : public Decision
{
public:

	ABDecision(Decision* a, Decision* b, Condition* c) : A(a), B(b), condition(c) {};

	virtual void makeDecision(Agent* agent, float deltaTime)
	{
		if (condition->test(agent))
		{
			A->makeDecision(agent, deltaTime);
		}
		else
		{
			B->makeDecision(agent, deltaTime);
		}
	}

protected:
	Decision* A;
	Decision* B;
	Condition* condition;
};

