#pragma once
#include "vector.h"
class Water
{
public:
	Water() {};
	float GiveWater() //this is called when creature drinks from this source
	{
		return waterPerConsume;
	}
private:
	vector2 position;
	float waterPerConsume = 10;
};

