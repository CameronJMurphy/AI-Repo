#pragma once
#include "Decision.h"
#include <dijkstrasSearch.h>
#include "SeekNodeBehaviour.h"
#include "ClosestNode.h"
#include "Dinosaur.h"
#include "Grass.h"
#include "Agent.h"

class FindFoodDecision : public Decision
{
public:
	FindFoodDecision(Pathfinding::Node* _target, std::vector<Pathfinding::Node*> _map) : target(_target), map(_map) {};
	FindFoodDecision(Agent* _target, std::vector<Pathfinding::Node*> _map) : agent_target(_target), map(_map) {};
	virtual void makeDecision(Agent* agent, float deltaTime);


private:
	Pathfinding::Node* target = nullptr; //stationary target
	Agent* agent_target = nullptr; //moving target
	std::vector<Pathfinding::Node*> map;
	std::list<Pathfinding::Node*> path;
	bool hasClosestNode = false;
};

