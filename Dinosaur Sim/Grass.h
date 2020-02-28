#pragma once
#include "Food.h"
#include "vector.h"
#include "Renderer2D.h"
#include <dijkstrasSearch.h>
class Grass : public Food
{
public:
	vector2 GetPosition() { return position; }
	void SetPosition(Pathfinding::Node* _pos) { position = vector2(_pos->position.x, _pos->position.y); }
	void Draw(aie::Renderer2D* r);
private:
	vector2 position;
};

