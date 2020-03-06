#include "FindWaterDecision.h"

void FindWaterDecision::makeDecision(Agent* agent, float  deltaTime) {
	Pathfinding::Node* closestNode = FindClosestNode(agent->GetPosition().x, agent->GetPosition().y, map);//find closest node to agent
	path = dijkstrasSearch(closestNode, target, map); //find the path towards food
	SeekNode(agent, deltaTime, path.front()); //seek towards next node in path
	path.pop_front(); //then pop front
}