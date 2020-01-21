#pragma once
#include <vector>
#include "Agent.h"
#include "Transition.h"

class State
{
public:

	State() {};
	virtual ~State() {};

	virtual void update(Agent* agent, float deltatime) = 0;
	virtual void init(Agent* agent) {};
	virtual void exit(Agent* agent) {};

	void addTransition(Transition* transition)
	{
		m_transitions.push_back(transition);
	}

	Transition* getTriggeredTransition(Agent* gameObject);

protected:
	std::vector<Transition*> m_transitions;
};

