#include "tsp.h"

Tsp::Tsp(const std::string& instanceFileName)
{
	std::ifstream in(instanceFileName);

	//exit if file couldn'tbe opened
	if ( !in.is_open() )
	{
		std::cerr << "Could not open a tsp instance" + instanceFileName + "\n";
		exit(0);
	}

	std::vector<Point> points;
	int numPoints, index;
	
	//resize vector to contain all points
	in >> numPoints;
	points.resize(numPoints);

	//load all points from file to points vector
	for (int i = 0 ; i < numPoints ; i++)
	{
		in >> index;
		in >> points[index - 1].x >> points[index - 1].y;
	}

	//create matrix from those points
	createMatrix(points);
	in.close();
}

Tsp::~Tsp()
{
	deleteSolver();
}

void Tsp::createMatrix(const std::vector<Point>& points)
{
	//resize matrix in accordance to number of points
	matrix.resize(points.size());
	for (auto& v : matrix)
		v.resize(points.size());

	//calculate distances between each point
	for (unsigned i = 0 ; i < points.size() ; i++)
	{
		//there is no edge to the same point, so set this edge's distance to infinity
		matrix[i][i] = INF;

		for (unsigned j = i + 1 ; j < points.size() ; j++)
			matrix[i][j] = matrix[j][i] = Point::distance(points[i], points[j]);
	}
}

void Tsp::solveGreedy()
{
	deleteSolver();

	solver = new TspGreedy(matrix);
	solver->startAlgorithm();	
}

void Tsp::solveAntColony(const AntColony::AntColonyParams& params)
{
	deleteSolver();

	solver = new AntColony(matrix, params);
	solver->startAlgorithm();
}

const std::list<int>& Tsp::getPath()
{
	if (solver == nullptr)
		throw "No algorithm was ran!";

	return solver->getTraveledPath();
}

double Tsp::getDistance()
{
	if (solver == nullptr)
		throw "No algorithm was ran!";

	return solver->getTraveledDistance();
}

void Tsp::deleteSolver()
{
	if (solver != nullptr)
		delete solver;
}