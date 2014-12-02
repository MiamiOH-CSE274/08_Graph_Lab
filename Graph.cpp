/*****
* Author   : brinkmwj
* Date     : 2009-11-06
* Sources  : All code is original
*/
#include "Graph.h"
#include <string>
#include <stack>
#include <iostream>

// Caroline Danzi
// 18 November 2014

// Originality Note: I worked by myself on this assigment.
// I looked up how to construct and use vectors on cplusplus.com
// and looked at their example code for syntax help.

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
	// Look through node1's list of edges to find one with
	// node2 as its destination, then return that cost
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
		if (adjList[node1].edgeList[i].dest == node2)
			return adjList[node1].edgeList[i].cost;
	}
	// If there is no edge, return -1
	return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
// If the edge already exists, just update the cost
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0){
		throw std::string("The cost of an edge cannot be negative.");
	}
	// Throw exceptions if the nodes are not in the graph
	if (node1 > adjList.size() - 1|| node1 < 0){
		throw std::string("The first node is not in this graph.");
	}
	if (node2 > adjList.size() - 1 || node2 < 0){
		throw std::string("The second node is not in this graph.");
	}
	else{
		// If the edge already exists, just update the cost and return
		// First look through node1's edgeList to see if there is an edge to node2
		for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
			// If there is an edge, update the cost in node1's list...
			if (adjList[node1].edgeList[i].dest == node2){
				adjList[node1].edgeList[i].cost = cost;
				// Then find the edge in node2's list and update its cost
				for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++){
					if (adjList[node2].edgeList[i].dest == node1)
						adjList[node2].edgeList[i].cost = cost;
				}
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
	// Throw exceptions if the nodes are not in the graph
	if (node1 > adjList.size() - 1 || node1 < 0){
		throw std::string("The first node is not in this graph.");
	}
	if (node2 > adjList.size() - 1 || node2 < 0){
		throw std::string("The second node is not in this graph.");
	}
	else{
		// Look for the edge in node1's list of edges and erase it
		for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++){
			// If the edge exists, erase it. Then look for the edge in node2's list
			if (adjList[node1].edgeList[i].dest == node2){
				adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);
				// Look for the edge in node2's list of edges and erase it
				for (unsigned int i = 0; i < adjList[node2].edgeList.size(); i++){
					if (adjList[node2].edgeList[i].dest == node1){
						adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + i);
						// We no longer need to look for the edge, so just return
						return;
					}
				}
			}
		}
	}
}

void Graph::DFS(int startingNode){
	// Throw an exception if the node is not in the graph
	if (startingNode > adjList.size() - 1 || startingNode < 0){
		throw std::string("The starting node is not in this graph.");
	}
	else{
		std::stack<int> open;
		// NOTE: In the closed list, 0 indicates the node has not been 
		// seen, 1 indicates it is in the open list, and 2 indicates
		// the node has been visited and is now in the closed list
		std::vector<int> closed;
		closed.resize(adjList.size());

		// Push the starting node onto the stack and indicate that
		// it is in the open list
		open.push(startingNode);
		closed[startingNode] = 1;

		while(!open.empty()){
			// Pop the last node off the stack, print it, and then
			// indicate it is closed
			int currentNode = open.top();
			open.pop();
			std::cout << currentNode << " ";
			closed[currentNode] = 2;

			// For each neighbor of the current node, add it to the open
			// list unless it is already there or it is in the closed list
			for(unsigned int i = 0; i < adjList[currentNode].edgeList.size(); i++){
				if(closed[adjList[currentNode].edgeList[i].dest] == 0){
					open.push(adjList[currentNode].edgeList[i].dest);
					closed[adjList[currentNode].edgeList[i].dest] = 1;
				}
			}
		}
	}
}
