#pragma once
#include "Behaviour.h"
#include <dijkstrasSearch.h>
#include "Agent.h"
class SeekNodeBehaviour :
	public Behaviour
{
public:
	SeekNodeBehaviour() {};
	virtual ~SeekNodeBehaviour() {};
	virtual vector2 Update(Agent* agent, float deltaTime);
	virtual float GetWeight() { return weight; };
	void SetTarget(Pathfinding::Node* t) { m_target = t; }
	void SetPath(std::list<Pathfinding::Node*> _path) { path = _path; }
	vector2 SeekNode(Agent* agent, float deltaTime);
	/*void SeekNode(Agent* agent, float deltaTime, Pathfinding::Node* target);*/
private:
	Pathfinding::Node* m_target;
	std::list<Pathfinding::Node*> path;
	float seekSpeed = 20;
	float weight = 1;
	
};

void SeekNode(Agent* agent, float deltaTime, Pathfinding::Node* target); //This is so other files can access this function