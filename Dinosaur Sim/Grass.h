#pragma once
#include "Food.h"
#include "vector.h"
#include "Renderer2D.h"
class Grass : public Food
{
public:
	vector2 GetPosition() { return position; }
	void SetPosition(vector2 _pos) { position = _pos; }
	void Draw(aie::Renderer2D* r);
private:
	vector2 position;
};

