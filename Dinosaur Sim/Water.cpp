#include "Water.h"

void Water::Draw(aie::Renderer2D* r) {
	r->drawBox(position.x, position.y, 200, 200); // Draw
}