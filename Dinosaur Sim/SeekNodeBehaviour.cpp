#include "SeekNodeBehaviour.h"


vector2 SeekNodeBehaviour::Update(Agent* agent, float deltaTime) {
	return SeekNode(agent, deltaTime);
}

vector2 SeekNodeBehaviour::SeekNode(Agent* agent, float deltaTime)
{
	SetTarget(path.front());
	vector2 force(0, 0);

	if (m_target == nullptr)
	{
		return force;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 targetPos = vector2(m_target->position.x, m_target->position.y); // target agent's pos

	vector2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
	direction.normalise();
	direction = direction * seekSpeed;

	force = direction - agent->GetVelocity();
	path.pop_front();

	return force;
}

void SeekNode(Agent* agent, float deltaTime, Pathfinding::Node* target)
{
	vector2 force(0, 0);

	if (target == nullptr)
	{
		return;
	}

	vector2 agentPos = agent->GetPosition(); //this agent's pos
	vector2 targetPos = vector2(target->position.x, target->position.y); // target agent's pos

	vector2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
	direction.normalise();
	float seekSpeed = 40;
	direction = direction * seekSpeed;

	force = direction - agent->GetVelocity();
	agent->SetVelocity(force);
	return;
}