#pragma once
#include "vector.h"
class Water
{
public:
	Water(vector2 pos) : position(pos) {};
	float GiveWater() //this is called when creature drinks from this source
	{
		return waterPerConsume;
	}
private:
	vector2 position;
	float waterPerConsume = 10;
};

