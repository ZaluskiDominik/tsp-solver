#include "tsp.h"
#include "tspinstancegenerator.h"
#include <ctime>
#include <utility>

class CmdArgumentsParser
{
public:
	explicit CmdArgumentsParser(int argc, char** argv);

	//execute specified action in cmd arguments
	void execute();

private:
	//specify what to do(solve greedy, solve ant colony or generate instance)
	//args: greedy, ant, gen
	std::string action;
	//what will be outputed after algorithm is done
	std::string outputMode = "all";
	//path to file where instance is stored, or in which generated instance will be saved
	std::string instanceFileName;
	std::vector<std::pair<std::string, double>> params;

	void parseKeyValuePairs(int argc, char** argv);

	//generate instance action
	void handleGenerateAction();

	//solve instance with greedy algorithm
	void handleGreedyAction();

	//solve instance with ant colony algorithm
	void handleAntAction();

	//display results on screen
	void handleOutput(Tsp& tsp);

	//outputs to stdout found path
	void outputPath(Tsp& tsp);

	//outputs to stdout found path and distance of this path
	void outputVerbose(Tsp& tsp);
};

CmdArgumentsParser::CmdArgumentsParser(int argc, char** argv)
{
	//check needed parameters were given
    if (argc < 3)
    {
    	std::cerr << "You had to specify action as a first argument and file name of instance as second argument!\n";
    	exit(0);
    }

	//first argument specify action that will be choosen
	action = argv[1];
	//second argument specify file name from which instance will be read, or to which instance will be generated
	instanceFileName = argv[2];

	parseKeyValuePairs(argc, argv);
}

void CmdArgumentsParser::parseKeyValuePairs(int argc, char** argv)
{
	for (int i = 3 ; i < argc ; i++)
	{
		std::string arg(argv[i]);
		//search for equal sign, which act as separator for parameters and values
		int separatorIndex = arg.find('=');
		
		//if it was found parse key value pairs
		if (separatorIndex != -1)
		{
			//parameter name
			std::string key = arg.substr(0, separatorIndex);
			//parameter value
			std::string value = arg.substr(separatorIndex + 1);

			//check if output mode was given
			if (key == "out")
				outputMode = value;
			else
			{
				//append new key value pair
				params.push_back( std::pair<std::string, double>{ key, 
			 		std::stod(value) } );
			}
		}
		else
		{
			//invalid argument
			std::cerr << "Invalid argument '" << arg << "'!\n";
			exit(0);
		}
	}
}

void CmdArgumentsParser::execute()
{
	if (action == "gen")
		handleGenerateAction();
	else if (action == "greedy")
		handleGreedyAction();
	else if (action == "ant")
		handleAntAction();
	else
	{
		std::cerr << "Unknown action!\n";
		exit(0);
	}
}

void CmdArgumentsParser::handleGenerateAction()
{
	//prepare instance parameters
	TspInstanceGenerator::GenInstanceParams genParams;
	for (const auto& arg : params)
	{
		if (arg.first == "num")
			genParams.numPoints = arg.second;
		else if (arg.first == "min")
			genParams.minCoordVal = arg.second;
		else if (arg.first == "max")
			genParams.maxCoordVal = arg.second;
	}

	TspInstanceGenerator gen(instanceFileName, genParams);
	gen.generate();
	std::cout << "Instance was generated!\n";
}

void CmdArgumentsParser::handleGreedyAction()
{
	Tsp tsp(instanceFileName);
	tsp.solveGreedy();
	handleOutput(tsp);
}

void CmdArgumentsParser::handleAntAction()
{
	//prepare parameters to ant colony
	AntColony::AntColonyParams antParams;
	for (const auto& arg : params)
	{
		if (arg.first == "time")
			antParams.msTimeLimit = arg.second;
		else if (arg.first == "ants")
			antParams.numAnts = arg.second;
		else if (arg.first == "alpha")
			antParams.alpha = arg.second;
		else if (arg.first == "betha")
			antParams.betha = arg.second;
		else if (arg.first == "evapor")
			antParams.pheromonesEvaporationRate = arg.second;
		else if (arg.first == "pher_incr")
			antParams.pheromonesIncreaseConst = arg.second;
		else
		{
			std::cerr << "Unknown argument '" << arg.first << "'\n";
			exit(0);
		}
	}

	Tsp tsp(instanceFileName);
	tsp.solveAntColony(antParams);
	handleOutput(tsp);
}

void CmdArgumentsParser::handleOutput(Tsp& tsp)
{
	if (outputMode == "path")
		outputPath(tsp);
	else if (outputMode == "dist")
		std::cout << tsp.getDistance() << "\n";
	else if (outputMode == "all")
		outputVerbose(tsp);
	else
	{
		std::cerr << "Unknown output mode! Defaulting to all mode...\n";
		outputVerbose(tsp);
	}
}

void CmdArgumentsParser::outputPath(Tsp& tsp)
{
	for (auto v : tsp.getPath())
		std::cout << v << " ";
}

void CmdArgumentsParser::outputVerbose(Tsp& tsp)
{
	std::cout << "Path: ";
	outputPath(tsp);
	std::cout << "\nDistance: " << tsp.getDistance() << "\n";
}

int main(int argc, char** argv)
{
    srand(time(0));

    CmdArgumentsParser parser(argc, argv);
    parser.execute();

	return 0;
}
