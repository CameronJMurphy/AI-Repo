#pragma once
class Food
{
public:
	float HungerValue() { return hungerValue; }
	void setHungerValue(float val) { hungerValue = val; }
protected:
	float hungerValue; //how much hunger will eating this restore
};

