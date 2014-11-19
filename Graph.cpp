/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Author 2 : Scott McCartney
 * Date 2   : 2014-11-17
 * Sources  : All code is original, samples were
 *      used as models and implemented as unique
 *      code for this project. Samples found here:
 *      http://www.cplusplus.com/reference/vector/vector/
 */
 
#include "Graph.h"
#include <iostream>

Graph::Graph(unsigned int numNodes){
    //resize the adjList container to the correct size of edges
    adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
    //Search node1 adjList for the edge to node2 and return cost
    for(int i = 0; i < adjList[node1].edgeList.size(); i++) {
        if(adjList[node1].edgeList[i].dest == node2) {
            return adjList[node1].edgeList[i].cost;
        }
    }
    
    //Returns -1.0 if the edge is not found/in the graph
    return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
    //check for a valid cost
    if(cost < 0.0) {
        throw std::string("In addEdge(), cost cannot be a negative number.");
    }
    
    //Nodes neet to be in the domain of adjList
    if(node1 < 0 || node1 > adjList.size()) {
        throw std::string("In addEdge(), node1 is not in the domain of adjList.");
    }
    else if(node2 < 0 || node2 > adjList.size()) {
        throw std::string("In addEdge(), node2 is not in the domain of adjList.");
    }
    
    //Change the cost of the edge if it exists
    
    
    //Edge does not exist, create edge in adjList with given cost
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
    //TODO
}

