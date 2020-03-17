#include "dijkstrasSearch.h"

bool CompareFloat(float a, float b)
{
    return fabs(a - b) < .001;
}

std::vector<Pathfinding::Node*> GenerateNodeMap(const int mapWidth, const int mapHeight, const float windowWidth, const float windowHeight)
{
    //generate list
    std::vector<Pathfinding::Node*> map;
    map.reserve(mapWidth * mapHeight);
    float nodeWidth = windowWidth / mapWidth;
    float nodeHeight = windowHeight / mapHeight;
    //fill in list
    for (int y = 0; y < mapHeight; ++y)
    {
        for (int x = 0; x < mapWidth; ++x)
        {
            Pathfinding::Node* n = new Pathfinding::Node(); //make node
            n->parent = NULL;
            n->position = Vector2(x * nodeWidth, y * nodeHeight); //set pos
            map.push_back(n); //push into list
        }
    }

    for (int n = 0; n < map.size(); ++n) //foreach node in map
    {
        auto node = map[n];
        std::list<Pathfinding::Edge> edges; //make a list of edges

        const int x = n % mapWidth;
        const int y = n / mapWidth;

        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (x + i >= 0 && x + i < mapWidth && y + j >= 0 && y + j < mapHeight && !(i == 0 && j == 0)) {
                    int neighbour_index = (y + j) * mapWidth + (x + i);
                    Pathfinding::Edge e; //make temp edge
                    e.target = map[neighbour_index]; //assign its target
                    edges.push_back(e); // push onto list
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

std::list<Pathfinding::Node*> dijkstrasSearch(Pathfinding::Node* startNode, Pathfinding::Node* endNode, std::vector<Pathfinding::Node*> map)
{
    using namespace Pathfinding;

    //reset nodes
    for (auto node : map) {
        node->gScore = 100000;
        node->parent = NULL;
        node->fScore = 100000;
        node->hScore = 100000;
    }
    // Validate the input
    if (startNode == NULL || endNode == NULL)
    {
        throw std::runtime_error("ERROR: NULL INPUTS");
    }

    if (startNode == endNode)
    {
        //throw std::runtime_error("ERROR: LIST HAS LENGTH OF ONE");
        std::list<Pathfinding::Node*> empty;
        empty.push_back(startNode);
        return empty;
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

void PosToNodeTranslation(float posX, float posY, //player pos
                          int mapX, int mapY,     //map dimensions
                          int windowX, int windowY)//window dimension
{

}