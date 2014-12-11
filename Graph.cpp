/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 *
 * Author	: meslerke
 * Date		: 11/16/14
 * Sources	: cplusplus.com for help with using vectors, geeksforgeeks.org for code for the last two methods
 */
#include "Graph.h"
#include <iostream>

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
	V = numNodes;
}

double Graph::getCost(int node1, int node2){
	if (node1 < 0 || node2 < 0) {
		throw std::string("Node1 and Node2 must both be at least 0.");
	}

	if ((unsigned int)node1 > adjList.size() || (unsigned int)node2 > adjList.size()) {
		throw std::string("Node1 and Node2 can't be greater than the total number of nodes.");
	}

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			return adjList[node1].edgeList[i].cost;
		}
	}
	
  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if (node1 < 0 || node2 < 0) {
		throw std::string("Node1 and Node2 cannot be smaller than 0.");
	}

	if ((unsigned int)node1 > adjList.size() || (unsigned int)node2 > adjList.size()) {
		throw std::string("Node1 and Node2 can't be greater than the total number of nodes.");
	}

	if (cost < 0) {
		throw std::string("ERROR: cost cannot be smaller than 0");
	}

	//Determine if the edge already exists. If so, update the cost
	if ((unsigned int)node1 < adjList.size()) {
		for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
			if (adjList[node1].edgeList[i].dest == node2) {
				adjList[node1].edgeList[i].cost = cost;

				//If the edge is found, then find the opposite and update the cost
				for (unsigned int i = 0; i < adjList[node2].edgeList.size(); i++) {
					if (adjList[node2].edgeList[i].dest == node1) {
						adjList[node2].edgeList[i].cost = cost;
						return;
					}
				}
			}
		}
	}
	//If the edge doesn't exist, then create it.
	//push_back adds to the end of the vector
	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));

}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	//Look to see if edge from node1 to node2 exists
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {
		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i); //erase edge from node1 to node2

			//Find edge from node2 to node1
			for (unsigned int i = 0; i < adjList[node2].edgeList.size(); i++) {
				if (adjList[node2].edgeList[i].dest == node1) {
					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + i); //erase edge from node2 to node1
				}
			}
		}
	}
}

//the code for these two methods were taken from www.geeksforgeeks.org and slightly edited by me
void Graph::DFSUtil(int v, bool visited[]) {

	visited[v] = true;
	std::cout << v << " " << std::endl;

	std::vector<Node>::iterator i;
	int num = 0;

	for (i = adjList.begin(); i != adjList.end(); ++i)
		if (!visited[num])
			DFSUtil(num, visited);
}

void Graph::DFS(int v) {
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}
