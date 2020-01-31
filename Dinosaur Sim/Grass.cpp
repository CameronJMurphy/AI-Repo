#include "Grass.h"

void Grass::Draw(aie::Renderer2D* r)
{
	r->drawBox(position.x, position.y, 10, 10); // Draw the agent
}