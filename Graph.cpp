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
	int retCost = -1;
	int edgeListSize = adjList.at(node1).edgeList.size();
	for(int i = 0; i < edgeListSize; i++){
		Edge edgeElement = adjList.at(node1).edgeList.at(i);
		if(edgeElement.dest == node2)
			retCost = edgeElement.cost;
	}
	return retCost;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	
	if(cost < 0)
		throw std::string("Cost cannot be less than zero");
	
	Edge* j = new Edge(cost, node2);
	Edge* k = new Edge(cost, node1);
	adjList.at(node1).edgeList.push_back(*(j));
	adjList.at(node2).edgeList.push_back(*(k));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  //TODO
}
