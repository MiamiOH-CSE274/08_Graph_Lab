/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
	for (unsigned int i = 0; i < numNodes; i++)
		adjList[i].edgeList.resize(numNodes - 1);
}

double Graph::getCost(int node1, int node2){
	for (unsigned int i = 0;i<adjList[node1].edgeList.size();i++){
		if (adjList[node1].edgeList[i].dest == node2){
			return adjList[node1].edgeList[i].cost;
		}
	}
	return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0){
		throw std::string("Can't have a negative cost.");
	}
	//finds pair node1,node2
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
		if (adjList[node1].edgeList[i].dest == node2){
			adjList[node1].edgeList[i].cost = cost;
			//finds pair node2, node1
			for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++){
				if (adjList[node2].edgeList[j].dest == node1){
					adjList[node2].edgeList[j].cost = cost;
					//break to save on processing power
					break;
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
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
		if (adjList[node1].edgeList[i].dest == node2){
			adjList[node1].edgeList[i].cost = -1;
			//finds pair node2, node1
			for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++){
				if (adjList[node2].edgeList[j].dest == node1){
					adjList[node2].edgeList[j].cost = -1;
					//break to save on processing power
					break;
				}
			}
		}
	}
	adjList[node1].edgeList.push_back(Edge(-1, node2));
	adjList[node2].edgeList.push_back(Edge(-1, node1));
}
