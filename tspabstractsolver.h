#ifndef TSPABSTRACTSOLVER_H
#define TSPABSTRACTSOLVER_H

#include <list>
#include <iostream>

//infinity
#define INF 0x7fffffff

class TspAbstractSolver
{
public:
	//returns list of vertexes, it's the best path that algorithm could find
	const std::list<int>& getTraveledPath()
	{
		return traveledPath;
	}

	//returns distance of path found by algorithm
	double getTraveledDistance()
	{
		return traveledDistance;
	}

	//starting point of an algorithm
	virtual void startAlgorithm() = 0;

protected:
	std::list<int> traveledPath;
	double traveledDistance;
};

#endif