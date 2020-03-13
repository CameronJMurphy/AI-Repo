#include "FindFoodDecision.h"

void FindFoodDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (!hasClosestNode)
	{
		Pathfinding::Node* closestNode = FindClosestNode(agent->GetPosition().x, agent->GetPosition().y, map);//find closest node to agent
		hasClosestNode = true;
		if (target != nullptr) {
			path = dijkstrasSearch(closestNode, target, map); //find the path towards food
		}
		else {
			path = dijkstrasSearch(closestNode, FindClosestNode(agent_target->GetPosition().x, agent_target->GetPosition().y, map), map); //find the path towards food
		}
		
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
		if (agent_target != nullptr)
		{
			//research to make sure target location hasn't changed
			Pathfinding::Node* closestNode = FindClosestNode(agent->GetPosition().x, agent->GetPosition().y, map);//find closest node to agent
			Pathfinding::Node* closestNodeTarget = FindClosestNode(agent_target->GetPosition().x, agent_target->GetPosition().y, map);//find closest node to agent
			if (closestNodeTarget == closestNode)
			{
				Dinosaur* dino = dynamic_cast<Dinosaur*>(agent);
				Dinosaur* dinoTarget = dynamic_cast<Dinosaur*>(agent_target);
				
				dinoTarget->setHungerValue(100);
				dinoTarget->Hurt(dino->GetDamage());
				if (dino != NULL)
				{
					dino->Eat(dinoTarget);
				}
			}
		}
		else {
			Dinosaur* dino = dynamic_cast<Dinosaur*>(agent);
			Grass* grassPatch = new Grass();
			grassPatch->setHungerValue(50);
			if (dino != NULL)
			{
				dino->Eat(grassPatch);

			}
		}
	}
}


