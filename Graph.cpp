/*****
* Author   : Sam Bowdler
* Date     : 2014-11-13
* Sources  : All code is original, empty template methods given from brinkmwj
*/
#include "Graph.h"

Graph::Graph(unsigned int numNodes) {
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2) {
	if (!(node1 >= adjList.size())){
		for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
			if (adjList[node1].edgeList[i].dest == node2)
				return adjList[node1].edgeList[i].cost;
		}
	}
	
	return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
//If the edge already exists, update the cost.
void Graph::addEdge(int node1, int node2, double cost) {
	if (cost < 0)
		throw std::string("ERROR: edge cost < 0");
	if (node1 >= adjList.size() || node2 >= adjList.size())
		throw std::string("ERROR: node is outside range");

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList[i].cost = cost;

			for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++) {
				if (adjList[node2].edgeList[j].dest == node1) {
					adjList[node2].edgeList[j].cost = cost;
					return;
				}
			}
		}
	}

	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2) {
	if(getCost(node1, node2) != -1.0) {
		for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
			if (adjList[node1].edgeList[i].dest == node2) {
				adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);

				for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++) {
					if (adjList[node2].edgeList[j].dest == node1) {
						adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + j);
						return;
					}
				}
			}
		}
	}
}
