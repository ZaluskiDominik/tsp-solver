#ifndef TSPGREEDY_H
#define TSPGREEDY_H

#include "tspabstractsolver.h"
#include <vector>

class TspGreedy : public TspAbstractSolver
{
public:
	explicit TspGreedy(const std::vector<std::vector<double>>& matrix);

	void startAlgorithm();

private:
	//graph in matrix representation
	const std::vector<std::vector<double>>& graph;

	//recursive greedy solver algorithm
	double solveGreedyHelper(int vertex, std::vector<bool>& visited);
};

#endif