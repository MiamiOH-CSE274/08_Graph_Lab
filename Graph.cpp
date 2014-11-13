/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

int Graph::getCost(int node1, int node2){
	// Look through node1's list of edges to find one with
	// node2 as its destination, then return that cost
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
		if (adjList[node1].edgeList[i].dest = node2)
			return adjList[node1].edgeList[i].cost;
	}
	// If there is no edge, return -1
	return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
// If the edge already exists, just update the cost
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0){
		throw new std::string("The cost of an edge cannot be negative.");
	}
	else{
		adjList[node1].edgeList[node2].cost = cost;
		adjList[node2].edgeList[node1].cost = cost;
	}
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  //TODO
}
