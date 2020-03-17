#include "FindWaterDecision.h"

void FindWaterDecision::makeDecision(Agent* agent, float  deltaTime) {
	if (!hasClosestNode)
	{
		Pathfinding::Node* closestNode = FindClosestNode(agent->GetPosition().x, agent->GetPosition().y, map);//find closest node to agent
		hasClosestNode = true;
		path = dijkstrasSearch(closestNode, target, map); //find the path towards food
	}
	if (path.size() > 0)
	{
		SeekNode(agent, deltaTime, path.front()); //seek towards next node in path
		if (fabs(path.front()->position.x - agent->GetPosition().x) < 1 &&
			fabs(path.front()->position.y - agent->GetPosition().y) < 1)//compare agent pos vs node pos
		{
			path.pop_front(); //then pop front
		}
	}
	if (path.size() == 0)
	{
		hasClosestNode = false;
		//DRINK
		Dinosaur* dino = dynamic_cast<Dinosaur*>(agent);
		Water* water = new Water();
		if (dino != NULL)
		{
			dino->Drink(water);
		}
	}
}