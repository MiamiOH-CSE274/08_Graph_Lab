/*****
 * Author   : Chris Mabe
 * Date     : 2014-11-18
 * Sources  : Headers - Dr. Brinkman, Inside of methods - Chris Mabe
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
  //TODO
  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
  //TODO
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  //TODO
}
