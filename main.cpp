#include "Graph.h"
#include <iostream>

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

int main(){
  testGraph();
    
    Graph testGraph(7);
    testGraph.addEdge(0, 4, 1);
    testGraph.addEdge(4, 2, 1);
    testGraph.addEdge(2, 3, 1);
    testGraph.addEdge(2, 5, 1);
    testGraph.addEdge(1, 0, 1);
    testGraph.addEdge(4, 1, 1);
    testGraph.addEdge(3, 5, 1);
    testGraph.addEdge(4, 3, 1);
    
    std::cout << "DFS traversal: ";
    testGraph.DFSTraversal(3);

  return 0;
}
