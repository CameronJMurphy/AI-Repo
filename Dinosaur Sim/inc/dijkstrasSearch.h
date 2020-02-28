#pragma once

#include <iostream>
#include <vector>
#include<list>
#include <math.h>



struct Vector2
{
    Vector2() : x(0), y(0){}
    Vector2(float X, float Y) : x(X), y(Y) {}
    float x;
    float y;
    float Magnitude()
    {
        return sqrt(x * x + y * y);
    }
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
        float gScore = 100000;
        float hScore = 100000;
        float fScore = 100000;
        Node* parent;
        std::vector< Edge > connections;

        bool operator <(Node* node)
        {
            if (node->fScore > fScore)
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

std::list<Pathfinding::Node*> GenerateNodeMap(const int width, const int height, const float windowWidth, const float windowHeight);

float Heuristic(Pathfinding::Node* _target, Pathfinding::Node* _endNode);

std::list<Pathfinding::Node*> dijkstrasSearch(Pathfinding::Node* startNode, Pathfinding::Node* endNode);

