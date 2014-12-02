#include <iostream>
#include "Graph.h"

void testGraph(){
    Graph g(10);
    g.addEdge(0,1,50);
    if(g.getCost(1,0) != 50 || g.getCost(0,1) != 50){
        std::cout << "ERROR: Expected edge cost of 50, got " << g.getCost(1,0) << std::endl;
        exit(1);
    } else {
        std::cout << "SUCCESS: Got the right edge cost" << std::endl;
    }
    
    if(g.getCost(2,3) != -1){
        std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(2,3) << std::endl;
        exit(1);
    } else {
        std::cout << "SUCCESS: Got the right edge cost for non-existent edge" << std::endl;
    }
    
    g.removeEdge(1,0);
    if(g.getCost(0,1) != -1 || g.getCost(1,0) != -1){
        std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(1,0) << std::endl;
        exit(1);
    } else {
        std::cout << "SUCCESS: Got the right edge cost for removed edge" << std::endl;
    }
    
}

void testTraversal() {
	Graph g(6);
	//Makes a graph like in my notebook for ease of testing
	g.addEdge(0,1,10);
	g.addEdge(0,5,10);
	g.addEdge(1,4,10);
	g.addEdge(4,5,10);
	g.addEdge(4,3,10);
	g.addEdge(3,2,10);
	g.addEdge(2,5,10);

	int nodeStart = 2;
	std::cout << "The DFS will start at node " << nodeStart <<
		", and should return: 2, 3, 4, 1, 0, 5" << std::endl;
	g.DFStraversal(2);
}

int main(){
    testGraph();
	testTraversal();
    
    return 0;
}
