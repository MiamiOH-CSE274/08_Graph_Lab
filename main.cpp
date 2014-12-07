#include "Graph.h"
#include <iostream>

void testGraph(){
  Graph g(10);
  g.addEdge(0,1,50);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 0, 3);
  g.addEdge(2, 4, 2);
  g.addEdge(4, 5, 2);
  g.addEdge(4, 7, 2);
  g.addEdge(2, 7, 2);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 9, 2);
  g.addEdge(4, 9, 2);
  g.addEdge(9, 8, 2);

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

  std::cout << "Depth First Traversal starting at node 2." << std::endl;
  g.DFS(2);

}

int main(){
  testGraph();

  return 0;
}
