#include "dijkstrasSearch.h"

bool CompareFloat(float a, float b)
{
    return fabs(a - b) < .001;
}

std::list<Pathfinding::Node*> GenerateNodeMap(const int mapWidth, const int mapHeight, const float windowWidth, const float windowHeight)
{
    //generate list
    std::list<Pathfinding::Node*> map;
    float nodeWidth = windowWidth / mapWidth;
    float nodeHeight = windowHeight / mapHeight;
    //fill in list
    for (int y = 0; y < mapHeight; ++y)
    {
        for (int x = 0; x < mapWidth; ++x)
        {
            Pathfinding::Node* n = new Pathfinding::Node(); //make node
            n->position = Vector2(x * nodeWidth, y * nodeHeight); //set pos
            map.push_back(n); //push into list
        }
    }

    for (auto node : map) //foreach node in map
    {
        std::list<Edge> edges; //make a list of edges
        for (auto n : map) //foreach node in map
        {
            if (n != node) //if they're not the same 
            {
                if (CompareFloat(n->position.y, node->position.y) ||
                    CompareFloat(n->position.y, node->position.y + nodeHeight) || 
                    CompareFloat(n->position.y, node->position.y - nodeHeight))//check to see if this node is within 1 position on y axis
                {
                    if (CompareFloat(n->position.x, node->position.x)|| 
                        CompareFloat(n->position.x, node->position.x + nodeWidth) || 
                        CompareFloat(n->position.x, node->position.x - nodeWidth)) //check to see if this node is within 1 position on x axis
                    {
                        Edge e; //make temp edge
                        e.target = n; //assign its target
                        edges.push_back(e); // push onto list
                    }
                }
            }
        }

        for (auto edge : edges) //foreach of the edges
        {
            node->connections.push_back(edge); //assign to the nodes connections
        }

    }
    return map; //return
}



float Heuristic(Pathfinding::Node* _target, Pathfinding::Node* _endNode)
{
    Vector2 heuristic(_endNode->position.x - _target->position.x, _endNode->position.y - _target->position.y);

    return heuristic.Magnitude();

}

std::list<Pathfinding::Node*> dijkstrasSearch(Pathfinding::Node* startNode, Pathfinding::Node* endNode)
{
    using namespace Pathfinding;
    // Validate the input
    if (startNode == NULL || endNode == NULL)
    {
        throw std::runtime_error("ERROR: NULL INPUTS");
    }

    if (startNode == endNode)
    {
        throw std::runtime_error("ERROR: LIST HAS LENGTH OF ONE");
    }

    // Initialise the starting node
    startNode->gScore = 0;
    startNode->parent = NULL;

    // Create our temporary lists for storing nodes we’re visiting/visited
    std::list<Node*> openList;
    std::list<Node*> closedList;

    openList.push_back(startNode);

    Node* currentNode;

    while (openList.size() != 0)
    {
        openList.sort(); //sort by fScore

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

        float gScore = 0;
        float hScore = 0;
        float fScore = 0;
        bool nodeFoundCL = false; //CL stands for closed list
        bool nodeFoundOL = false; //OL stands for openList
        for (Edge c : currentNode->connections)
        {
            for (Node* node : closedList)//is this target in the closedList
            {
                if (node == c.target)
                {
                    nodeFoundCL = true; //yes it was found
                }
            }
            if (!nodeFoundCL)
            {
                gScore = currentNode->gScore + c.cost;
                hScore = Heuristic(c.target, endNode);
                fScore = gScore + hScore;
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
                    c.target->fScore = fScore;
                    c.target->parent = currentNode;
                    openList.push_back(c.target);
                }
                // Node is already in the openList with a valid Score.
                // So compare the calculated Score with the existing
                // to find the shorter path.
                else if (fScore < c.target->fScore)
                {
                    c.target->gScore = gScore;
                    c.target->fScore = fScore;
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