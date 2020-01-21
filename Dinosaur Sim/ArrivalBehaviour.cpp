#include "ArrivalBehaviour.h"



ArrivalBehaviour::ArrivalBehaviour()
{
}


ArrivalBehaviour::~ArrivalBehaviour()
{
}

vector2 ArrivalBehaviour::Update(Agent* agent, float deltaTime)
{
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return force;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 targetPos = m_target->GetPosition(); // target agent's pos
	vector2 distanceToTarget = targetPos - agentPos;

	vector2 direction(distanceToTarget.x / targetsRadius, distanceToTarget.y / targetsRadius);
	direction.normalise();
	direction = direction * speed;

	force = direction - agent->GetVelocity();

	return force;
}