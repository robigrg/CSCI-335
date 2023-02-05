// Homework 5
// Name: Robi Gurung
// Date: 10 December 2021
// graph.h
/*
A graph class and a corner struct are included in this application. 
The graph class has operations for reading text files for nodes and generating 
an proximity list, which is represented as a list. It then employs Dijkstra's 
method to determine the shortest path between these nodes by referring to the 
proximity list and calculating the weights of each edge to determine the most 
efficient path.
*/

#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <cmath>
#include <cfloat>

using namespace std;

class Graph{
public:
  struct Corner{
    // Here Corneris a structure that has four variables.
    // The vertices map to which it is linked, the point to which it is linked, 
    // to calculate range and the route to the point.
    int point; double range; 
    list<int> route; map<int, double> vertices; 
    bool operator<(const Corner &rhs) const{
      // if the ranges is not equal to the right hand side of the range then
      // return the less point which is less than the right hand side of the 
      // point or just return that the range is less that the right hand side of 
      // the range.
      if(range == rhs.range){return (point< rhs.point);}
      return (range < rhs.range);
    }
  };

  Graph(){
    // Graph function with the inital rate of the scale as zero.
    scale = 0; 
  }

  void CreateGraph(string filename){
    // CreateGraph function is created. This method will open a text file and parse 
    // it by space. Variables with string, integer and double are introduced. Here,
    // In the text file, there is a line which is holded by insert_bar and the first
    // line in the text file by first_bar. The edge's mass is stored by mass.
    // The rate of the point will be set on point_rate and the rate of the mass on 
    // mass rate. The point_string will hold the line from the text file that is reading.
    int point_rate;
    double mass_rate;
    string insert_bar, mass, first_bar, point_string;     
    ifstream fin(filename);
    getline(fin, first_bar);
    scale = stoi(first_bar); //turns a string into an integer value.
    while(getline(fin, insert_bar)){
      Corner plot; // a corner object is created named plot
      stringstream strstream(insert_bar);
      getline(strstream, point_string, ' ');
      point_rate = stoi(point_string); //turns a string into an integer value.
      plot.point = point_rate;
      while(getline(strstream,point_string,' ')){   
        // data parsing the line for a point and a mass
        getline(strstream, mass, ' ');
        point_rate = stoi(point_string); //turns a string into an integer value.
        mass_rate = stod(mass); //Parses str and converts it to a floating-point integer, which is then returned as a double value.
        plot.vertices[point_rate] = mass_rate;
      }
      next_list.push_back(plot);
    }

  }

  void PrintGraph(){
    // PrintGraph function is created. This method iterates through the 
    // proximity list and prints the graph that results.
    for(list<Corner>::iterator it=next_list.begin(); it != next_list.end(); it++){
      cout << it->point; // print the point
      for(map<int,double>::iterator i = it->vertices.begin(); i != it->vertices.end(); i++){
        cout << " " << i->first << " " << i->second; // print the first and second vertices
      }
    }
  }


// @filename: the query file that we are getting from the terminal
// @func: this function will open the text file and iterate through our list of Vertices, and then
//  iterate through the maps we created in order to see if the points are connected
  void Link(string filename){
    // Link function is created. This technique will open the text file and 
    // cycle through our list of Vertices and maps to see whether the points are linked. We will be 
    // storing the first corner in the point_one and on point_two, we will be stroing the corner for 
    // which we will be checking the relations with. Two string variables are introduced to tally for
    // the connections.
    int point_one, point_two;                                  
    string insert_bar, point_string;
    ifstream fin(filename);
    while(getline(fin, insert_bar)){ 
      // obtaining and reading the initial point from the text file, parsing the data and then
      // moving on to the next point
      stringstream strstream(insert_bar);
      getline(strstream, point_string, ' '); 
      point_one = stoi(point_string); //turns a string into an integer value.
      getline(strstream, point_string, ' ');    
      point_two = stoi(point_string); //turns a string into an integer value.
      list<Corner>::iterator it = next_list.begin();
      advance(it, point_one - 1); // shifting the iterator point_one - 1 spaces
      // checking if the vertices[point_two] is equal to 0.0 or not.
      // Then the output should be:
      // 4 1: not_connected 
      // 3 4: connected 50.2 
      // 1 5: connected 0.5 
      // 5 1: not_connected 
      // 1 3: not_connected
      // where the numbers to the right of “connected” are the weight of this edge.                  
      if(it->vertices[point_two] == 0.0){
        cout << point_one << " " << point_two << ": not_connected" << endl; }
      else{
        cout << point_one << " " << point_two << ": connected " << it->vertices[point_two] << endl;}
    }
  }

  // Then the output should be:
  // 1: 1 cost: 0.0
  // 2: 1 2 cost: 2.0
  // 3: 1 4 3 cost: 3.0
  // 4: 1 cost: 1.0
  // 5: 1 4 5 cost: 3.0
  // 6: 1 4 7 6 cost: 6.0
  // 7: 1 4 7 cost: 5.0
  // The first number is the target vertex. (Aka: the last line beginning with 7: is the shortest path 
  // from the input starting vertex 1, to the target vertex 7.) Your output should always be ordered this way, 
  // starting from target vertex 1, to the maximum target vertex for that graph. Following the target vertex,
  // display the path taken, inclusive of the starting and ending vertices. Finally, display “cost:” followed 
  // by the cost of that path. There is a special case, that may arise based on the input graph and the starting 
  // vertex. This is the case when there is no path from a starting vertex to the destination. 
  void DijkstraAlgorithm(int point){
    // DijkstraAlgorithm function is created. This function will apply the Dijkstra algorithm to 
    // the points in the graph and discover the shortest feasible path to the point provided to it.
    // We have a double variable range_power which is set to zero which will be used to store and compare
    // the range.
    list<Corner>::iterator first = next_list.begin();
    advance(first, point - 1); 
    // shifting the iterator point_one - 1 spaces
    list<Corner>::iterator itr;
    for(itr = next_list.begin(); itr != next_list.end(); itr++){
      // setting each graph point's range to the point that has been passed through to infinity
      itr->range = std::numeric_limits<double>::infinity();
    }
    itr = next_list.begin();
    first->range = 0.0; // changing the range of a point to 0
    first->route.push_back(first->point);

    BinaryHeap <Corner> corner_load; 
    unordered_set <int> check_mark;
    corner_load.insert(*first);
    Corner head;
    while(!corner_load.isEmpty()){
      // while the corener_load is not empty, if it is true then we delete the minimum of the head.
      // We will also insert the current point into the check_mark set.
      corner_load.deleteMin(head);
      check_mark.insert(head.point);
      map<int, double>::iterator itr;
      for(itr = head.vertices.begin(); itr != head.vertices.end(); itr++){
        // iterating over the temporary Corner object's proximity list
        list<Corner>::iterator point_one = next_list.begin(); 
        advance(point_one, itr->first-1); // shifting the iterator point_one - 1 spaces
        Corner &next_point = *point_one;
        // checking if the point isn't in the unsorted list of points visited or not.
        if (!check_mark.count(next_point.point)){
          double range_power = 0.0; 
          range_power = head.range + head.vertices[next_point.point];
          // checking if the new range is smaller than the current range. If so then the range variable 
          // should be updated.
          if (range_power < next_point.range){
            next_point.range = range_power;
            next_point.route = head.route;
            next_point.route.push_back(next_point.point);
          }
          corner_load.insert(next_point);
        }
      }
    }
  }

  // There is a special case, that may arise based on the input graph and the starting vertex. 
  // This is the case when there is no path from a starting vertex to the destination.  In such 
  // cases you should include the word not_possible in your output. This case arises multiple times 
  // in the following:
  // Then the output should be
  // 1: not_possible
  // 2: not_possible
  // 3: not_possible
  // 4: not_possible
  // 5: not_possible
  // 6: 7 6 cost: 1.0
  // 7: 7 cost: 0.0
  // The above means that there no paths starting from 7 to 1, 2, 3, 4, and 5.
  // So, when there is no path to a target vertex, add the word not_possible in your output.


  void PrintDijkstra(){
    // PrintDijkstra function is created. This function displays the shortest path to a given location 
    // from all other points in the graph, as determined using the Dijkstra algorithm.
    for(list<Corner>::iterator itr =next_list.begin(); itr != next_list.end(); itr++){
        cout << itr->point << ": ";
        for(auto const& i: itr->route){
          cout << i << " ";
        }
        if(itr-> range == std::numeric_limits<double>::infinity()){
          cout << "not_possible"; //printing statement
        }
        else{
            cout << "cost: " << itr-> range;
        }
        cout <<"\n";
      }
  }
  

private:
  list<Corner> next_list;   //list of vertices
  int scale;
};




#endif