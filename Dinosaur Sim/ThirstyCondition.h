#pragma once
#include "Condition.h"
#include "Dinosaur.h"
class ThirstyCondition : public Condition
{
public:
	ThirstyCondition() {}
	virtual ~ThirstyCondition() {}

	virtual bool test(Agent* agent) const
	{
		Dinosaur* dino = dynamic_cast<Dinosaur*>(agent);
		if (dino != NULL)
		{
			if (dino->GetCurrentThirst() < (dino->GetMaxThirst() / 1.5)) //if the dino has less then 50% of its max thirst
			{
				return true; //it is thirsty
			}
		}
		return false; // it isn't thirsty
	}

	virtual vector2 Update(Agent* gameObject, float deltaTime) //return nothing
	{
		vector2* v = new vector2(0, 0);
		return *v;
	};
	virtual float GetWeight() { return 0; };
};

