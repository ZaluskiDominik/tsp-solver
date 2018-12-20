#ifndef ANT_COLONY
#define ANT_COLONY

#include <vector>
#include "ant.h"
#include "tspabstractsolver.h"

class AntColony : public TspAbstractSolver
{	
public:
	//strucute of parameters to this algorithm
	struct AntColonyParams
	{
		int msTimeLimit = 4000;
		int numAnts = 300;
		double alpha = 1.0;
		double betha = 2.0;
		double pheromonesEvaporationRate = 0.05;
		double pheromonesIncreaseConst = 1000.0;
	};

	//struct holding distance and number of pheromones between two vertexes
	struct Edge
	{
		//distance beetwen two nodes
		double distance;
		//number of pheromones on this edge
		double pheromones;
	};

	//constructor as parameters takes graph matrix with distances between nodes, and algorithm parameters
	explicit AntColony(const std::vector<std::vector<double>>& graph, const AntColonyParams& _params = defaultParams);

	void startAlgorithm();

private:
	static AntColonyParams defaultParams;

	const AntColonyParams params;

	//graph in matrix representation
	std::vector<std::vector<Edge>> graph;
	//vector containing all created ants
	std::vector<Ant> ants;

	//creates graph made of Edge structure from regular graph matrix
	void initGraph(const std::vector<std::vector<double>>& matrix);

	//creates ants
	void spawnAnts();

	//resets ants positions to start positions and reset all their data structures
	void resetAnts();

	//move all ants to next vertex
	void moveAnts();

	//calculates numerator of ant's probability to move to given vertex
	double calcEdgeAttractivness(int fromIndex, int toIndex);

	//returns sum of edge attractivess to ant moving from currentIndex to all possible unvisited nodes
	double calcSumOfEdgeAttractivness(const Ant& ant);

	//updates number of pheromones on each edge
	void updatePheromones();

	//checks if better path was found by any ant
	void updateBestPath();

	//calculates sum of pheromones deposited by ants on given edge
	double calcSumOfPheromonesDeposited(int fromVertex, int toVertex);
};

#endif