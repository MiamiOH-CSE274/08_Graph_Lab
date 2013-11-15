/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"
#include <iostream>

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
	std::cout << adjList.size() << std::endl;
	for (int i = 0; i < adjList.size(); i++){
		Edge();
		adjList[i].edgeList.resize(1);
		std::cout << adjList[i].edgeList.size() << std::endl;
	}
}

int Graph::getCost(int node1, int node2){
  //TODO 
	int cost2 = -1;
	std::cout << adjList.size() << std::endl;
	for (int i = 0; i < adjList.size(); i++){
		for (int j = 0; j < adjList[node1].edgeList.size(); j++){
			if(adjList[node1].edgeList[j].dest == node2)
				cost2 = adjList[node1].edgeList[j].cost;
		}
	}
 return cost2;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
  
	if (cost < 0)
		throw std::string("cost < 0");

	for (int i = 0; i < adjList.size(); i++){
		for (int j = 0; j < adjList[node1].edgeList.size(); j++){
			if ((adjList[node1].edgeList[j].cost == -1) && (adjList[node1].edgeList[j].dest == -1)){
				adjList[node1].edgeList[j].cost = cost;
				adjList[node1].edgeList[j].dest = node2;
			}
		}
		for (int j = 0; j < adjList[node2].edgeList.size(); j++){
			if ((adjList[node2].edgeList[j].cost == -1) && (adjList[node2].edgeList[j].dest == -1)){
				adjList[node2].edgeList[j].cost = cost;
				adjList[node2].edgeList[j].dest = node1;
			}
		}
	}
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
  //TODO
	for (int i = 0; i < adjList.size(); i++){
		for (int j = 0; j < adjList[node1].edgeList.size(); j++){
			if ((adjList[node1].edgeList[j].cost != -1) && (adjList[node1].edgeList[j].dest != -1)){
				adjList[node1].edgeList[j].cost = -1;
				adjList[node1].edgeList[j].dest = -1;
			}
		}
		for (int j = 0; j < adjList[node2].edgeList.size(); j++){
			if ((adjList[node2].edgeList[j].cost != -1) && (adjList[node2].edgeList[j].dest != -1)){
				adjList[node2].edgeList[j].cost = -1;
				adjList[node2].edgeList[j].dest = -1;
			}
		}
	}
}
