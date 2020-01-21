#pragma once

#include <iostream>
#include <vector>
#include<list>

struct Vector2
{
    Vector2() : x(0), y(0){}
    Vector2(float X, float Y) : x(X), y(Y) {}
    float x;
    float y;
};

struct Edge;

namespace Pathfinding
{
    
    struct Node
    {
        Node() {}
        ~Node() {}
        // User defined data attached to each node.
        Vector2 position;
        float gScore;
        Node* parent;
        std::vector< Edge > connections;

        bool operator <(Node* node)
        {
            if (node->gScore > gScore)
            {
                return true;
            }
            return false;
        }
    };

}

struct Edge
{
    Pathfinding::Node* target;
    float cost;
};


std::list<Pathfinding::Node*> dijkstrasSearch(Pathfinding::Node* startNode, Pathfinding::Node* endNode)
{
    using namespace Pathfinding;
    // Validate the input
    if (startNode == NULL || endNode == NULL)
    {
        std::cout << "Error";
        std::runtime_error;
    }

    if (startNode == endNode)
    {
        std::cout << "Error";
        std::runtime_error;
    }

    // Initialise the starting node
    startNode->gScore = 0;
    startNode->parent = NULL;

    // Create our temporary lists for storing nodes we�re visiting/visited
    std::list<Node*> openList;
    std::list<Node*> closedList;

    openList.push_back(startNode);

    Node* currentNode;

    while (openList.size() != 0)
    {
        openList.sort();

        currentNode = openList.front();
        // If we visit the endNode, then we can exit early.
        // Sorting the openList guarantees the shortest path is found,
       // given no negative costs (a prerequisite of the algorithm).
        if (currentNode == endNode)
        {
            break;
        }

        openList.remove(currentNode);
        closedList.push_back(currentNode);

        int gScore = 0;
        bool nodeFoundCL = false; //CL stands for closed list
        bool nodeFoundOL = false; //OL stands for openList
        for (Edge c : currentNode->connections)
        {
            for (Node* node : closedList)//is this target in the closedList
            {
                if (node == c.target)
                {
                    nodeFoundCL == true; //yes it was found
                }
            }
            if (!nodeFoundCL)
            {
                gScore = currentNode->gScore + c.cost;

                // Have not yet visited the node.
                // So calculate the Score and update its parent.
                // Also add it to the openList for processing.
                for (Node* node : openList)//is this target in the openList
                {
                    if (node == c.target)
                    {
                        nodeFoundOL = true; //yes it was found
                    }
                }
                if (!nodeFoundOL)
                {
                    c.target->gScore = gScore;
                    c.target->parent = currentNode;
                    openList.push_back(c.target);
                }
                // Node is already in the openList with a valid Score.
                // So compare the calculated Score with the existing
                // to find the shorter path.
                else if (gScore < c.target->gScore)
                {
                    c.target->gScore = gScore;
                    c.target->parent = currentNode;
                }
            }

        }

    }
    // Create Path in reverse from endNode to startNode 
    std::list<Node*> path;
    currentNode = endNode;

    while (currentNode != NULL)
    {
        path.push_front(currentNode);
        currentNode = currentNode->parent;
    }
    // Return the path for navigation between startNode/endNode 
    return path;
}
