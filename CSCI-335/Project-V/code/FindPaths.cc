// Homework 5
// Name: Robi Gurung
// Date: 10 December 2021
// FindPaths.cc 
/*
This program includes the pathfinder's driver, as well as 
the setup of a graph object, the Dijkstra algorithm application 
to the graph, and the printing of the shortest path from all nodes 
in the graph to a specified node.
*/

#include "graph.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pathfindDriver(int argc, char **argv) {
  Graph run;
  run.CreateGraph(argv[1]);
  int zzz = stoi(argv[2]);
  run.DijkstraAlgorithm(zzz);
  run.PrintDijkstra();
  return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }
    pathfindDriver(argc, argv);
    return 0;
}