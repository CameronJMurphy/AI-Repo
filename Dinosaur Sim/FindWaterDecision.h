#pragma once
#include "Decision.h"
#include <dijkstrasSearch.h>
#include "SeekNodeBehaviour.h"
#include "ClosestNode.h"
#include "Dinosaur.h"
class FindWaterDecision : public Decision
{
public:
	FindWaterDecision(Pathfinding::Node* _target, std::vector<Pathfinding::Node*> _map) : target(_target), map(_map) {};
	virtual void makeDecision(Agent* agent, float deltaTime);


private:
	Pathfinding::Node* target;
	std::vector<Pathfinding::Node*> map;
	std::list<Pathfinding::Node*> path;
	bool hasClosestNode = false;
};

