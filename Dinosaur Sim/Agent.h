#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include <vector.h>
#include "Behaviour.h"
class Agent
{
public:
	Agent();
	virtual ~Agent();
	// Update the agent and its behaviours
	virtual void Update(float deltaTime);
	// Draw the agent
	virtual void Draw(aie::Renderer2D* renderer);
	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);
	// Movement functions
	void SetPosition(vector2 position) { m_Position = position; }
	vector2 GetPosition() const { return m_Position; }
	void SetVelocity(vector2 velocity) { m_Velocity = velocity; }
	vector2 GetVelocity() { return m_Velocity; }
	void ClampVelocity(vector2& force);

protected:
	std::vector<Behaviour*> m_BehaviourList;
	vector2 m_Position;
	vector2 m_Velocity;
	vector2* m_MaxVelocity = new vector2(50, 50);


};

