#include "IdleDecision.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime)
{
	vector2 agentSpeed = agent->GetVelocity(); //get speed
	//start to slow the agent down 
	float slowAmount = 1.001f;
	if (agentSpeed.x != 0)
	{
		agentSpeed.x /= slowAmount;
	}
	if (agentSpeed.y != 0)
	{
		agentSpeed.y /= slowAmount;
	}

	agent->SetVelocity(agentSpeed);

};
