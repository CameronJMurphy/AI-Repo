#include "SeekNodeBehaviour.h"


vector2 SeekNodeBehaviour::Update(Agent* agent, float deltaTime) {

	SetTarget(path.front());
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return force;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 targetPos = vector2 (m_target->position.x, m_target->position.y); // target agent's pos

	vector2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
	direction.normalise();
	direction = direction * seekSpeed;

	force = direction - agent->GetVelocity();
	path.pop_front();

	return force;
}
