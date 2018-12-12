#include "tspgreedy.h"

TspGreedy::TspGreedy(const std::vector<std::vector<double>>& matrix)
	:graph(matrix) {}

void TspGreedy::startAlgorithm()
{
	//clear traveled path
	traveledPath.clear();

	//vertexes visited
	std::vector<bool> visited;
	visited.resize(graph.size());

	//set all vertexes to unvisited
	for (auto v : visited)
		v = false;

	//solve greedy starting from vertex 0
	traveledDistance = solveGreedyHelper(0, visited);
}

double TspGreedy::solveGreedyHelper(int vertex, std::vector<bool>& visited)
{
	int minIndex = -1;
	double minDistance = INF;

	visited[vertex] = true;
	traveledPath.push_back(vertex + 1);

	for (unsigned i = 0 ; i < graph.size() ; i++)
	{
		if ( !visited[i] && graph[vertex][i] < minDistance )
		{
			minDistance = graph[vertex][i];
			minIndex = i;
		}
	}

	//if all vertexes were visited
	if (minIndex == -1)
	{
		//go again to start vertex
		traveledPath.push_back(1);
		return graph[vertex][0];
	}

	return minDistance + solveGreedyHelper(minIndex, visited);
}