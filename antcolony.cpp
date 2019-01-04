#include "antcolony.h"
#include <ctime>
#include <cmath>

AntColony::AntColonyParams AntColony::defaultParams;

AntColony::AntColony(const std::vector<std::vector<double>>& graph, const AntColonyParams& _params)
	:params(_params)
{
	traveledDistance = INF;
	initGraph(graph);
	spawnAnts();
}

void AntColony::startAlgorithm()
{
	double startTime, endTime;
	startTime = clock();
	
	//continue algorithm while elapsed time is less that time limit
	do
	{
		resetAnts();
		
		//move ants until all vertex won't be visited
		for (unsigned i = 1 ; i < graph.size() ; i++)
			moveAnts();

		//go back to start vertex with all ants(hamilton cicle will be completed)
		for (auto& ant : ants)
			ant.move(ant.startVertex, graph[ant.currVertex][ant.startVertex].distance);

		//update pheromones on edges
		updatePheromones();
				
		//check if better path than currently the best path was found by any ant
		updateBestPath();

		endTime = clock();
	}
	while ( (endTime - startTime) / CLOCKS_PER_SEC * 1000 < params.msTimeLimit );	
}

void AntColony::initGraph(const std::vector<std::vector<double>>& matrix)
{
	//resize graph
	graph.resize(matrix.size());
	for (auto& row : graph)
		row.resize(graph.size());

	for (unsigned i = 0 ; i < graph.size() ; i++)
	{
		graph[i][i].pheromones = 0;
		graph[i][i].distance = INF;
		
		for (unsigned j = i + 1 ; j < graph.size() ; j++)
		{
			graph[i][j].distance = graph[j][i].distance = matrix[i][j];
			graph[i][j].pheromones = graph[j][i].pheromones = 100.0;
		}
	}
}

void AntColony::spawnAnts()
{
	ants.resize(params.numAnts);
	for (auto& ant : ants)
	{
		//set ant's start position to random vertex
		int startIndex = std::rand() % graph.size();
		ant = Ant(graph.size(), startIndex);
	}
}

void AntColony::resetAnts()
{
	for (auto& ant : ants)
		ant.reset();
}

void AntColony::moveAnts()
{
	for (auto& ant : ants)
	{
		double attractivness, sumOfAttractivness = calcSumOfEdgeAttractivness(ant), sumOfProb = 0;

		for (unsigned i = 0 ; i < graph.size() ; i++)
		{
			//if vertex i wasn't visited by ant
			if ( !ant.visited[i] )
			{
				//calculate attractivness of trasition from ant's current vertex to vertex i
				attractivness = calcEdgeAttractivness(ant.currVertex, i);
				
				//calc move probability to vertex i
				double moveProbability = attractivness / sumOfAttractivness;
				
				sumOfProb += moveProbability;
				
				//some random probability(prevents ant from constantly choosing edges with max probability)
				double randomNumber = static_cast<double>(std::rand() % 1000) / 1000.0;

				//if sum of move probabilities is greater or equal to random number then go to vertex i
				//else continue checking other possible vertexes
				if ( sumOfProb >= randomNumber )
				{
					ant.move(i, graph[ant.currVertex][i].distance);
					break;
				}
			}
		}
	}
}

double AntColony::calcEdgeAttractivness(int fromIndex, int toIndex)
{
	const Edge& edge = graph[fromIndex][toIndex];
	return pow(edge.pheromones, params.alpha) * pow(1/edge.distance, params.betha);
}

double AntColony::calcSumOfEdgeAttractivness(const Ant& ant)
{
	double sum = 0;

	//sum edges attractivness from ant's startIndex to all unvisited nodes
	for (int i = 0 ; i < graph.size() ; i++)
	{
		//if node i wasn't already visited
		if ( !ant.visited[i] )
			sum += calcEdgeAttractivness(ant.currVertex, i);
	}

	return sum;
}

void AntColony::updatePheromones()
{
	for (int i = 0 ; i < graph.size() ; i++)
	{
		for (int j = i + 1 ; j < graph.size() ; j++)
		{
			double pheromones = (1 - params.pheromonesEvaporationRate) * ( graph[i][j].pheromones + calcSumOfPheromonesDeposited(i, j) );
			graph[i][j].pheromones = graph[j][i].pheromones = pheromones;
		}
	}
}

void AntColony::updateBestPath()
{
	std::vector<Ant>::iterator bestAnt = ants.begin();
	
	//find ant that has choosen the shortest hamilton cicle
	for (auto i = ants.begin() + 1 ; i < ants.end() ; i++)
		if (i->traveledDistance < bestAnt->traveledDistance)
			bestAnt = i;

	//if path of that ant is shorter from currently the shortest found, then this ant's path becomes new the best path
	if (bestAnt->traveledDistance < traveledDistance)
	{
		traveledPath = bestAnt->traveledPath;
		traveledDistance = bestAnt->traveledDistance;
	}
}

double AntColony::calcSumOfPheromonesDeposited(int fromVertex, int toVertex)
{
	double sum = 0;

	for (auto& ant : ants)
	{
		//if ant used edge between fromVerex and toVertex, then add pheromones
		if (ant.edgesTransitions[fromVertex] == toVertex || ant.edgesTransitions[toVertex] == fromVertex)
			sum += params.pheromonesIncreaseConst / graph[fromVertex][toVertex].distance;
	}

	return sum;
}
