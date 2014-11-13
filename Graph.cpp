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
		if (adjList[node1].edgeList[i].dest == node2)
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
		// If the edge already exists, just update the cost and return
		for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
			if (adjList[node1].edgeList[i].dest == node2){
				adjList[node1].edgeList[i].cost = cost;
				adjList[node2].edgeList[i].cost = cost;
				return;
			}
		}
		// Otherwise, add and Edge to node1's list of edges
		// and to node2's list of edges
		adjList[node1].edgeList.push_back(Edge(cost, node2));
		adjList[node2].edgeList.push_back(Edge(cost, node1));
	}
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	// Look for the edge in node1's list of edges and erase it
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
		if (adjList[node1].edgeList[i].dest == node2)
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);
	}
	// Look for the edge in node2's list of edges and erase it
	for (unsigned int i = 0; i < adjList[node2].edgeList.size(); i++){
		if (adjList[node2].edgeList[i].dest == node1)
			adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + i);
	}
}
