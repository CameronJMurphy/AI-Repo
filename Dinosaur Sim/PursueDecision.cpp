#include "PursueDecision.h"

void PursueDecision::makeDecision(Agent* agent, float deltaTime)
{
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 targetPos = m_target->GetPosition(); // target agent's pos

	vector2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
	direction.normalise();
	direction = direction * m_speed;

	force = direction - agent->GetVelocity();
	agent->SetVelocity(force);

	return;
}
