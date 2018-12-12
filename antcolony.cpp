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
		double attractivness, sumOfAttractivness = 0;
		int bestVertex = -1;
		double maxAttractivness = -1;

		//find maximal probability of transition from startVertex to some other vertex
		for (unsigned i = 0 ; i < graph.size() ; i++)
		{
			//if vertex i wasn't visited by ant
			if ( !ant.visited[i] )
			{
				//calculate attractivness of trasition from ant's current vertex to vertex i
				attractivness = calcEdgeAttractivness(ant.currVertex, i);
				//add that attractivness to sum of attractivness of move to all unvisited vertexes 
				sumOfAttractivness += attractivness;
				
				//if attractivness of move to vertex i is greater than currently max found attractivness
				if (attractivness > maxAttractivness)
				{
					//new max attractivness is found
					maxAttractivness = attractivness;
					bestVertex = i;
				}
			}
		}

		//calc move probability to bestVertex using maxAttractivness
		double moveProbability = (sumOfAttractivness) ? attractivness / sumOfAttractivness : 0;

		//make a move with this ant
		moveAntBasedOnProbability(ant, bestVertex, moveProbability);
	}
}

void AntColony::moveAntBasedOnProbability(Ant& ant, int toVertex, double moveProbability)
{
	//some random probability(prevents ant from being stack in loop if there is too much pheromones on edge)
	double randomNumber = static_cast<double>(std::rand() % 1000) / 1000.0;

	if (moveProbability > randomNumber)
	{
		//go to vertex where probability of optimal move is maximal
		ant.move(toVertex, graph[ant.currVertex][toVertex].distance);
	}
	else
	{
		//random factor wins
		//go to the nearest vertex
		double minDistance = INF;
		int minVertex = -1;

		//find that nearest vertex
		for (int i = 0 ; i < graph.size() ; i++)
		{
			if ( !ant.visited[i] && graph[ant.currVertex][i].distance < minDistance )
			{
				minDistance = graph[ant.currVertex][i].distance;
				minVertex = i;
			}
		}

		ant.move(minVertex, graph[ant.currVertex][minVertex].distance);
	}
}

double AntColony::calcEdgeAttractivness(int fromIndex, int toIndex)
{
	const Edge& edge = graph[fromIndex][toIndex];
	return pow(edge.pheromones, params.alpha) * pow(1/edge.distance, params.betha);
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