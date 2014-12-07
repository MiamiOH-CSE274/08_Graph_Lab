/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
 
 // Kyle Busdieker
// Prof. Bo Brinkman
// Date: November 22, 2014
// The skeleton code was created by Bo Brinkman and modified by Kyle Busdieker with help from other students, Open Data Structures textbook, and the internet.
#include "Graph.h"
#include <iostream>
#include <list>

using namespace std;

Graph::Graph(unsigned int numNodes){

	numVerts = numNodes;
	adjList.resize(numNodes);

}

double Graph::getCost(int node1, int node2){

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++)
		if (adjList[node1].edgeList[i].dest == node2 && node1 < adjList.size())
			return adjList[node1].edgeList[i].cost;


  return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){

	if (cost < 0)
		throw std::string("The cost must be greater than 0.");

	if (node1 < 0)
		throw std::string("Node1 can't be less than 0.");

	if (node2 < 0)
		throw std::string("Node2 can't be less than 0.");

	if (node1 > adjList.size())
		throw std::string("Node1 can't be greater than the number of nodes.");

	if (node2 > adjList.size())
		throw std::string("Node2 can't be greater than the number of nodes.");

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {

		if (adjList[node1].edgeList[i].dest == node2) {
			adjList[node1].edgeList[i].cost = cost;

			for (unsigned int ii = 0; ii < adjList[node2].edgeList.size(); i++) 
				
				if (adjList[node2].edgeList[ii].dest == node1)
					adjList[node2].edgeList[ii].cost = cost;

			return;
		}
	}

	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++) {

		if (adjList[node1].edgeList[i].dest == node2) {

			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);

			for (unsigned int ii = 0; ii < adjList[node2].edgeList.size(); i++) {

				if (adjList[node2].edgeList[ii].dest = node1) {

					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + i);
					return;
				}
			}
		}
	}
}

// The original code for this was found on www.geeksforgeeks.org and modified by Kyle Busdieker
void Graph::DFSUtil(int v, bool visited[]) {

	visited[v] = true;
	cout << v << " ";

	int counter = 0;
	vector<Node>::iterator i;

	for (i = adjList.begin(); i < adjList.end(); i++, counter++)
		if (!visited[counter])
			DFSUtil(counter, visited);

}

void Graph::DFS(int v) {

	bool* visited = new bool[numVerts];

	for (int i = 0; i < numVerts; i++)
		visited[i] = false;

	DFSUtil(v, visited);

}
