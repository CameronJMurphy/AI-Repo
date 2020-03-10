#pragma once
#include "vector.h"
#include <dijkstrasSearch.h>
#include "Renderer2D.h"
class Water
{
public:
	//Water(vector2 pos) : position(pos) {};
	vector2 GetPosition() { return position; }
	void SetPosition(Pathfinding::Node* _pos) { position = vector2(_pos->position.x, _pos->position.y); }
	void Draw(aie::Renderer2D* r);
	float WaterValue() //this is called when creature drinks from this source
	{
		return waterPerConsume;
	}
private:
	vector2 position;
	float waterPerConsume = 100;
};

