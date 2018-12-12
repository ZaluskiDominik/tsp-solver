tsp: main.o tsp.o tspinstancegenerator.o tspgreedy.o antcolony.o ant.o
	g++ -o tsp main.o tsp.o tspinstancegenerator.o tspgreedy.o antcolony.o ant.o
main.o: main.cpp point.h
	g++ -c main.cpp
tsp.o: tsp.h tsp.cpp
	g++ -c tsp.h tsp.cpp
tspinstancegenerator.o: tspinstancegenerator.h tspinstancegenerator.cpp
	g++ -c tspinstancegenerator.h tspinstancegenerator.cpp
tspgreedy.o: tspabstractsolver.h tspgreedy.h tspgreedy.cpp
	g++ -c tspabstractsolver.h tspgreedy.h tspgreedy.cpp
antcolony.o: antcolony.cpp antcolony.h
	g++ -c antcolony.cpp antcolony.h point.h
ant.o: ant.h ant.cpp
	g++ -c ant.h ant.cpp
