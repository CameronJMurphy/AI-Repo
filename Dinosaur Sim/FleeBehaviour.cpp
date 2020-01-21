#include "FleeBehaviour.h"



FleeBehaviour::FleeBehaviour()
{
}


FleeBehaviour::~FleeBehaviour()
{
}

vector2 FleeBehaviour::Update(Agent* agent, float deltaTime)
{
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return force;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 targetPos = m_target->GetPosition(); // target agent's pos

	vector2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
	direction.normalise();
	direction = direction * fleeSpeed;
	direction = direction * -1;

	force = direction - agent->GetVelocity();

	return force;
}
