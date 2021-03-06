#include "WanderBehaviour.h"



WanderBehaviour::WanderBehaviour()
{
}


WanderBehaviour::~WanderBehaviour()
{
}

vector2 WanderBehaviour::Update(Agent* agent, float deltaTime)
{
	//circle center
	vector2 circleCenter(0,0);
	circleCenter = agent->GetVelocity();
	circleCenter.normalise();
	circleCenter = circleCenter * distanceToSphere;
	
	//Displacement Force
	vector2 displacement(0, -1);
	displacement = displacement * radius;
	//change vector direction
	setAngle(displacement, jitter);

	//update jitter
	jitter += ( rand() * angleChange) - (angleChange * .5);

	//update force
	vector2 force(0, 0);
	force = circleCenter + displacement;
	force.normalise();

	return force * speed;

}

void WanderBehaviour::setAngle(vector2& vec, float value)
{
	float length = vec.magnitude();
	vec.x = cos(value) * length;
	vec.y = sin(value) * length;
}