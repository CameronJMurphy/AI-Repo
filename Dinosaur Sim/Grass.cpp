#include "Grass.h"

void Grass::Draw(aie::Renderer2D* r)
{
	r->drawBox(position.x, position.y, 100, 100); // Draw
}