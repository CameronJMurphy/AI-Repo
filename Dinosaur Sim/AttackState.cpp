#include "AttackState.h"

void AttackState::update(Agent* gameObject, float delta)
{
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return;
	}

	vector2 agentPos = gameObject->GetPosition(); //this agent's pos
	vector2 targetPos = m_target->GetPosition(); // target agent's pos

	vector2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
	direction.normalise();
	direction = direction * m_speed;

	force = direction - gameObject->GetVelocity();
	gameObject->SetVelocity(force);

	return;
}
