#include "KeyboardBehaviour.h"



KeyboardBehaviour::KeyboardBehaviour()
{
}


KeyboardBehaviour::~KeyboardBehaviour()
{
}

vector2 KeyboardBehaviour::Update(Agent* agent, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	vector2 force(0, 0); //set up force var

	float movespeed = 20;
	
	//apply movespeed depending of input
	if (input->isKeyDown(aie::INPUT_KEY_UP)) force.y = movespeed;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN)) force.y = -movespeed;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT)) force.x = -movespeed;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) force.x = movespeed;

	return force;
}

