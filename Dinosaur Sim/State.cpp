#include "State.h"


Transition* State::getTriggeredTransition(Agent* gameObject)
{
	for (auto transition : m_transitions)
	{
		if (transition->hasTriggered(gameObject))
		{
			return transition;
		}
	}
	return nullptr;
}