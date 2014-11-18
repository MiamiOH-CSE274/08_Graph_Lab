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

Graph::Graph(unsigned int numNodes){
    //resize the adjList container to be able to use it
    adjList.resize(numNodes);
}

double Graph::getCost(int node1, int node2){
    //TODO
    return -1.0;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
    //TODO
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
    //TODO
}
