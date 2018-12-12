#ifndef POINT
#define POINT

#include <cmath>

//struct representing a point with integer coordinates
struct Point
{
	int x, y;

	//calculates distance between two points
	static double distance(const Point& a, const Point& b)
	{
		return (sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) ));
	}
};

#endif