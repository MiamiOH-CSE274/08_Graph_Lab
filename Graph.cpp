/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 *
 *
 * Author   : Nick Cooperrider
 * Date     : 2014-11-18
 * Sources  : All code is original with some code provided by brinkmwj
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){

	adjList.resize(numNodes);

}

double Graph::getCost(int node1, int node2){

	if(node1 < adjList.size() && node2 < adjList.size()) {
		for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
			if(adjList[node1].edgeList[i].dest == node2) {
				return adjList[node1].edgeList[i].cost;
			}
		}
	}
  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){

	if(cost < 0) {
		throw std::string("Error: Cost can not be less than zero");
	}
	
	if(node1 < adjList.size() && node2 < adjList.size()) {
		for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
			if(adjList[node1].edgeList[i].dest == node2) {
				for(unsigned int j = 0; j < adjList[node1].edgeList.size(); j++) {
					if(adjList[node2].edgeList[j].dest == node1) {
						adjList[node2].edgeList[j].cost = cost;
						adjList[node1].edgeList[i].cost = cost;
						throw std::string("There is already an edge between these nodes, updating cost"); 
					}
				}
			}
		}
	}
	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){

	if(node1 < adjList.size() && node2 < adjList.size()) {

		for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
			if(adjList[node1].edgeList[i].dest == node2) {
				adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);
			}
		}

		for(unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
			if(adjList[node2].edgeList[i].dest == node1) {
				adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + i);
			}
		}
	}
}
