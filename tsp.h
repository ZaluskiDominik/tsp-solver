#include <fstream>
#include <iostream>
#include <cstdlib>
#include "point.h"
#include "antcolony.h"
#include "tspgreedy.h"

#ifndef TSP_H
#define TSP_H

class Tsp
{
public:
	Tsp(const std::string& instanceFileName);
	~Tsp();

	//solves instance using greedy algorithm
	void solveGreedy();

	//solves instance with ant colony algorithm
	void solveAntColony(const AntColony::AntColonyParams& params);
	
	//returns best path computed by an algorithm
	const std::list<int>& getPath();

	//returns distance of best path which was found by an algorithm
	double getDistance();

private:
	std::vector<std::vector<double>> matrix;
	//pointer to solver instance which was solving tsp problem
	TspAbstractSolver* solver = nullptr;

	//create matrix represetaton of graph from vector of points
	void createMatrix(const std::vector<Point>& points);

	//deletes solver if it existed
	void deleteSolver();
};

#endif