#pragma once
#include "Condition.h"
#include "Dinosaur.h"
class HungryCondition : public Condition
{
public:
	HungryCondition() {}
	virtual ~HungryCondition() {}

	virtual bool test(Agent* agent) const
	{
		Dinosaur* dino = dynamic_cast<Dinosaur*>(agent); //turn agent to Dinosaur type
		if (dino != NULL)//safety check
		{
			if (dino->GetCurrentHunger() < (dino->GetMaxHunger() / 2)) //if the dino has less then 50% of its max hunger
			{
				return true; //it is hungry
			}
		}
		return false; // it isn't hungry
	}

	virtual vector2 Update(Agent* gameObject, float deltaTime) //return nothing
	{
		vector2* v = new vector2(0, 0);
		return *v;
	};
	virtual float GetWeight() { return 0; };
};

