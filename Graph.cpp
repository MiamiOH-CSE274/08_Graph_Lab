/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	for (unsigned int y = 0; y < numNodes; y++){
		for (unsigned int x = 0; x < adjList[y].edgeList.size; x++){
			adjList[y].edgeList[x] = Edge();
		}
	}
}

double Graph::getCost(int node1, int node2){
	for (unsigned int x = 0; x < adjList[node1].edgeList.size; x++){
		if (adjList[node1].edgeList[x].dest == node2){
			return adjList[node1].edgeList[x].cost;
		}
	}
  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0){
		throw std::string("Negative cost is not allowed");
	}
	for (unsigned int x = 0; x < adjList[node1].edgeList.size; x++){
		if (adjList[node1].edgeList[x].dest == node2){
			adjList[node1].edgeList[x] = Edge(cost, node2);
		}
	}
	for (unsigned int x = 0; x < adjList[node2].edgeList.size; x++){
		if (adjList[node2].edgeList[x].dest == node1){
			adjList[node2].edgeList[x] = Edge(cost, node1);
		}
	}
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	for (unsigned int x = 0; x < adjList[node1].edgeList.size; x++){
		if (adjList[node1].edgeList[x].dest == node2){
			adjList[node1].edgeList[x] = Edge();
		}
	}
	for (unsigned int x = 0; x < adjList[node2].edgeList.size; x++){
		if (adjList[node2].edgeList[x].dest == node1){
			adjList[node2].edgeList[x] = Edge();
		}
	}
}
