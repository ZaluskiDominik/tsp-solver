#ifndef TSP_INSTANCE_GENERATOR_H
#define TSP_INSTANCE_GENERATOR_H

#include <fstream>
#include <string>

class TspInstanceGenerator
{
public:
	//struct holding parameters of tsp instance that will be generated
	struct GenInstanceParams
	{
		int numPoints = 300;
		int minCoordVal = 1000;
		int maxCoordVal = 7000;
	};

	//parameters as follows: file name to which instance will be saved, optionally parameters of instance to generate
	explicit TspInstanceGenerator(const std::string& fileName, const GenInstanceParams& params = defaultParams);

	//generates instance to file
	void generate();

private:
	static GenInstanceParams defaultParams;
	//parameters of this instance
	GenInstanceParams params;

	//file to which generated instance will be saved
	std::string outputFileName;
};

#endif