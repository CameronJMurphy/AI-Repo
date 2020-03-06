#include "ClosestNode.h"

Pathfinding::Node* FindClosestNode(float posX, float posY, std::vector<Pathfinding::Node*> _map)
{
	Pathfinding::Node* closestNode = _map.front(); //setup our closest node var
	for (auto node : _map) //foreach node
	{
		if (fabs(posX - node->position.x) <= fabs(posX - closestNode->position.x) && //if this node is closer to the desired position than the current closest node
			fabs(posY - node->position.y) <= fabs(posY - closestNode->position.y))
		{
			closestNode = node; //set node to closet node
		}
	}
	return closestNode; //return
}