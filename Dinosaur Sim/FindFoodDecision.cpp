#include "FindFoodDecision.h"

void FindFoodDecision::makeDecision(Agent* agent, float deltaTime)
{
	Pathfinding::Node* closestNode = FindClosestNode(agent->GetPosition().x, agent->GetPosition().y, map);//find closest node to agent

	path = dijkstrasSearch(closestNode, target); //find the path towards food

	SeekNode(agent, deltaTime, path.front()->connections.front().target); //seek towards next node in path
	path.pop_front(); //then pop front
}
