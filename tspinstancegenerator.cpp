#include "tspinstancegenerator.h"

TspInstanceGenerator::GenInstanceParams TspInstanceGenerator::defaultParams;

TspInstanceGenerator::TspInstanceGenerator(const std::string& fileName, const GenInstanceParams& params)
{
	outputFileName = fileName;
	this->params = params;
}

void TspInstanceGenerator::generate()
{
	std::ofstream out(outputFileName);

    //output number of points
    out << params.numPoints << "\n";

    //output index of point and generated coordinates
    for (int i = 0 ; i < params.numPoints ; i++)
    {
        out << i + 1;
        
        for (int j = 0 ; j < 2 ; j++)
        	out << " " << std::rand() % (params.maxCoordVal - params.minCoordVal + 1) + params.minCoordVal;
        
        out << "\n";
    }

    out.close();
}