#pragma once
#include "Condition.h"
#include "Agent.h"

class WithinRangeCondition : public Condition
{
public:
	WithinRangeCondition(const Agent* target, float range) : m_target(target), m_range(range) {}
	virtual ~WithinRangeCondition() {}

	virtual bool test(Agent* gameObject) const
	{
		//get target pos
		vector2 targetPos(0, 0);
		targetPos = m_target->GetPosition();

		//get my pos
		vector2 myPos(0, 0);
		myPos = gameObject->GetPosition();

		//compare the two and get the distance between them
		float xDiff = targetPos.x - myPos.x;
		float yDiff = targetPos.y - myPos.y;
		float distance = sqrtf(xDiff * xDiff + yDiff * yDiff);

		return distance <= m_range;
	}

	virtual vector2 Update(Agent* gameObject, float deltaTime) //return nothing
	{
		vector2* v = new vector2(0, 0);
		return *v;
	};
	virtual float GetWeight() { return 0; };

private:
	const Agent* m_target;
	float m_range;
};

