#pragma once
#include "Decision.h"
#include <dijkstrasSearch.h>
#include "SeekNodeBehaviour.h"
#include "ClosestNode.h"

class FindFoodDecision : public Decision
{
public:
	FindFoodDecision(Pathfinding::Node* _target, std::list<Pathfinding::Node*> _map) : target(_target), map(_map) {};
	virtual void makeDecision(Agent* agent, float deltaTime);


private:
	Pathfinding::Node* target;
	std::list<Pathfinding::Node*> map;
	std::list<Pathfinding::Node*> path;
};

