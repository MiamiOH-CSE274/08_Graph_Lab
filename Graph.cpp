/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"

// used resize from http://www.cplusplus.com/reference/vector/vector/resize/
//
Graph::Graph(unsigned int numNodes){
    adjList.resize(numNodes);
    for (int i = 0; i < adjList.size(); i++)
      adjList[i].edgeList.resize(1);
        
    
}


int Graph::getCost(int node1, int node2){
 int p=0;
    
    // go though all the nodes
    for (int i=0; i<adjList.size(); i++) {
       // go though all the lists on each node
        
        
        while(p < adjList[node1].edgeList.size()){
        if(adjList[node1].edgeList[p].dest==node2)
            
            return adjList[node1].edgeList[i].cost;
        p++;
       
        }
    }
    
    return -1;

}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
 if(cost<=0)
    throw  ("Cost can't be less than zero");
    
 else{
    for (int j = 0; j < adjList[node1].edgeList.size(); j++){
        
        if (adjList[node1].edgeList[j].cost == -1){
            if(adjList[node1].edgeList[j].dest == -1){
               adjList[node1].edgeList[j].dest = node2;
               adjList[node1].edgeList[j].cost = cost;
                  }
        }
    }
    
    for (int p = 0; p < adjList[node2].edgeList.size(); p++){
        
        if (adjList[node2].edgeList[p].cost == -1){
            
            if(adjList[node2].edgeList[p].dest == -1){
                adjList[node2].edgeList[p].dest = node1;
                adjList[node2].edgeList[p].cost = cost;
            
            }
        }

    
    
    
}
}
}
// erase from http://www.cplusplus.com/reference/vector/vector/erase/
// remove method from book
//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
      int p=0;
           
            while(p < adjList[node2].edgeList.size()){
               if(adjList[node2].edgeList[p].dest==node1)
            adjList[node2].edgeList.erase(adjList[node2].edgeList.begin()+p);
                    
            p++;
         
            }
        }
    
    
    int q=0;
    while(q < adjList[node1].edgeList.size()){
        if(adjList[node1].edgeList[q].dest==node2)
            adjList[node1].edgeList.erase(adjList[node1].edgeList.begin()+q);
            
        q++;
       
        }
    }
}
