// AI_Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "dijkstrasSearch.h"



int main()
{
	//structure looks like this
	//		>N5--1-->N4
	//	   /		   \
	//    1			    1
	//	 /				 \>
	//	N1--10-->N2--10-->N3

	//set up list of nodes
	std::list<Pathfinding::Node*> nodes;

	//set up node positions
	Pathfinding::Node* node1 = new Pathfinding::Node();
	node1->position.x = 0;
	node1->position.y = 0;
	
	Pathfinding::Node* node2 = new Pathfinding::Node();
	node2->position.x = 1;
	node2->position.y = 0;
	
	Pathfinding::Node* node3 = new Pathfinding::Node();
	node3->position.x = 2;
	node3->position.y = 0;
	
	Pathfinding::Node* node4 = new Pathfinding::Node();
	node4->position.x = 1.5;
	node4->position.y = 1;
	
	Pathfinding::Node* node5 = new Pathfinding::Node();
	node5->position.x = 0.5;
	node5->position.y = 1;
	

	//set up edges

	Edge edge1;
	edge1.target = node2;
	edge1.cost = 10;
	Edge edge2;
	edge2.target = node3;
	edge2.cost = 10;
	Edge edge3;
	edge3.target = node3;
	edge3.cost = 1;
	Edge edge4;
	edge4.target = node4;
	edge4.cost = 1;
	Edge edge5;
	edge5.target = node5;
	edge5.cost = 1;

	
	node1->connections.push_back(edge1);
	node1->connections.push_back(edge5);
	node2->connections.push_back(edge2);
	node4->connections.push_back(edge3);
	node5->connections.push_back(edge4);

	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);

	dijkstrasSearch(node1, node3);

	//clean up
	for (auto node : nodes)
	{
		delete node;
	}


}