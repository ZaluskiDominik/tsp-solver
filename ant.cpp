#include "ant.h"

Ant::Ant(int numVertex, int startVertex)
	:startVertex(startVertex)
{
	visited.resize(numVertex);
	edgesTransitions.resize(numVertex);
	reset();
}

void Ant::reset()
{
	currVertex = startVertex;
	traveledDistance = 0;

	traveledPath = std::list<int>{startVertex + 1};
	
	//reset transitions
	for (auto& v : edgesTransitions)
		v = -1;

	//reset each node to unvisited state
	for (auto v : visited)
		v = false;

	//mark start vertex as visited
	visited[startVertex] = true;
}

void Ant::move(int toVertex, double distance)
{
	//mark vertex where ant will move as visited
	visited[toVertex] = true;
	//add vertex to traveled vertexes list
	traveledPath.push_back(toVertex + 1);

	edgesTransitions[currVertex] = toVertex;

	//increase total distance traveled by the ant
	traveledDistance += distance;
	//cahnge current vertex
	currVertex = toVertex;
}