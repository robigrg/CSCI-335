// Homework 5
// Name: Robi Gurung
// Date: 10 December 2021
// CreateGraphAndTest.cc 
/*
This program builds a GRaph object and executes the methods 
used to build the graph, writing out the nodes that are nearby 
as well as the weights on the edges if they are related.
*/

#include "graph.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int graphTestDriver(int argc, char **argv) {
    Graph run;
    run.CreateGraph(argv[1]);
    run.Link(argv[2]);
    return 0;
}

int main(int argc, char **argv) {
    graphTestDriver(argc, argv);
    return 0;
}