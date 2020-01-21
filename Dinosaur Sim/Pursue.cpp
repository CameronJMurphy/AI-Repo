#include "Pursue.h"



PursueBehaviour::PursueBehaviour()
{
}


PursueBehaviour::~PursueBehaviour()
{
}

vector2 PursueBehaviour::Update(Agent* agent, float deltaTime)
{
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return force;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 direction = m_target->GetPosition() + m_target->GetVelocity() - agent->GetPosition(); // target pos

	direction.normalise();
	direction = direction * Speed;

	force = direction - agent->GetVelocity();

	return force;
}