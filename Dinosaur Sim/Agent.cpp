#include "Agent.h"

bool Agent::WithinBounds(vector2 pos) {
	if (pos.x > windowDimensions.x ||
		pos.x < 0 ||
		pos.y > windowDimensions.y ||
		pos.y < 0) {
		return false;
	}
	return true;
}

Agent::~Agent()
{
}

 void Agent::Update(float deltaTime)
{
	 vector2 force(0,0); //set up force var
	 for(auto behaviour : m_BehaviourList)//call update on each behaviour
	 {
		force = force + behaviour->Update(this, deltaTime) * behaviour->GetWeight();

		ClampVelocity(force);
	 }
	 m_Velocity = m_Velocity + (force * deltaTime);//calculate velocity
	 ClampVelocity(m_Velocity);

	 if (WithinBounds(m_Position + (m_Velocity * deltaTime))) {
		 m_Position = m_Position + (m_Velocity * deltaTime);//apply velocity to position
	 }	 
}


 void Agent::Draw(aie::Renderer2D* renderer)
{
	 renderer->drawBox(m_Position.x, m_Position.y, 10, 10); // Draw the agent
}

void Agent::AddBehaviour(Behaviour* behaviour)
{
	m_BehaviourList.push_back(behaviour); // Add a behaviour to the agent
}

void Agent::ClampVelocity(vector2& force)
{
	if (force.x >= m_MaxVelocity->x) //clamp velocity positive
	{
		force.x = m_MaxVelocity->x;
	}
	if (force.y >= m_MaxVelocity->y)
	{
		force.y = m_MaxVelocity->y;
	}

	if (force.x <= -1 * m_MaxVelocity->x) //clamp velocity negitive
	{
		force.x = -1 * m_MaxVelocity->x;
	}
	if (force.y <= -1 * m_MaxVelocity->y)
	{
		force.y = -1 * m_MaxVelocity->y;
	}
}