#ifndef ANT
#define ANT

#include <vector>
#include <list>

struct Ant
{
	explicit Ant() = default;
	explicit Ant(int numVertex, int startVertex);

	int startVertex;
	int currVertex;

	//total distance traveled by the ant
	double traveledDistance;

	//vector that indicate whether given node was visited by this ant(instant info if node `i` was visited)
	std::vector<bool> visited;
	//list of next nodex that were visited by the ant
	std::list<int> traveledPath;
	std::vector<int> edgesTransitions;
	
	//resets state of the ant and restore start position
	void reset();

	//moves ant to given toVertex
	void move(int toVertex, double distance);
};

#endif