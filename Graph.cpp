/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

// Basic for loop from Open Data Structures, and the rest from me

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
	//find a node that links to node2, return cost
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			return adjList[node1].edgeList[i].cost;
		}
	}
	//no edge
	return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0){
		throw std::string("Cost can't be negative.");
	}

	//edge exists , update cost
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList[i].cost = cost;

			for (unsigned int k = 0; k < adjList[node2].edgeList.size(); k++) {
				if (adjList[node2].edgeList[k].dest == node1) {
					adjList[node2].edgeList[k].cost = cost;
					return;
				}
			}
		}
	}
	//edge doesn't exist, create one
	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	// remove specified edge from both nodes
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);

			for (unsigned int k = 0; i < adjList[node1].edgeList.size(); k++) {
				if (adjList[node2].edgeList[k].dest == node1) {
					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + k);
					return;
				}
			}
		}
	}
}
