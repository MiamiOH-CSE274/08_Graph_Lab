
/*****
 * Author   : brinkmwj
 * Date     : 2009-11-06
 * Sources  : All code is original
 */
#include "Graph.h"
#include <stack>
#include <iostream>
Graph::Graph(unsigned int numNodes){
    adjList.resize(numNodes);
    //used for resize http://www.cplusplus.com/reference/vector/vector/resize/
    for (int i = 0; i < numNodes; i++) {
        adjList[i].edgeList.resize(numNodes);
    }
}

int Graph::getCost(int node1, int node2){
    
    //pv short for possibleVertices.
    int pv=adjList[node1].edgeList.size();
    //run through the edgelist to see if there is an edge with dest==2
    for (int i=0; i<pv; i++) {
        //if node 1's edgeList at [i] points to node2 return that cost.
        if (adjList[node1].edgeList[i].dest==node2) {
            //return the cost.
            return adjList[node1].edgeList[i].cost;
        }
    }
    //else return -1
    return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
    //looked at https://github.com/MiamiOH-CSE274/08_Graph_Lab/blob/bickledb/Graph.cpp
    //to see how to access &adjList, from there it was basic pointers.
    
    Node* toAdd = &adjList[node1];
    //set node1's edgelist at node2 to have cost and to have dest node2
    toAdd->edgeList[node2].cost = cost;
    toAdd->edgeList[node2].dest = node2;
    //do the same for node2's edgelist at node1.
    toAdd = &adjList[node2];
    toAdd->edgeList[node1].cost = cost;
    toAdd->edgeList[node1].dest = node1;
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
    //do nothing if no such edge.
    
    int m=-1;
    //change m if we find node1 has an edge to node2. if m does not change than we don't have an
    //edge  between them so we do nothing and return.
    for (int i=0; i<adjList[node1].edgeList.size(); i++) {
        if (adjList[node1].edgeList[i].dest==node2) {
            m=i;
        }
    }
    if (m==-1) {
        return;
    }
    
    Node* toDel = &adjList[node1];
    //set edgeList[node2] cost and del to defuaults
    toDel->edgeList[node2].cost=-1;
    toDel->edgeList[node2].dest=-1;
    //do the same for &adjList[node2]
    toDel = &adjList[node2];
    toDel->edgeList[node1].cost=-1;
    toDel->edgeList[node1].dest=-1;
    
}
void Graph::DFS(int node1){
    //bool allSeen= false;
    int count=0;
    std::stack<int> open;
    open.push(node1);
    int* status = new int[adjList.size()];
    for (int i =0; i<adjList.size(); i++) {
        status[i]=0;

    }
    status[node1]=1;
    while(open.size()!=0) {
        count++;
        int v = open.top();
        std::cout << v << ", " << std::endl;
        open.pop();
        status[v]=2;

        for(int j=0; j<adjList[v].edgeList.size(); j++) {
        //testing out !=2
            if (status[j]!=2) {
            // std::cout << "hi";
                status[j]=1;
         
              if (!(adjList[v].edgeList[j].cost==-1))
                  open.push(j);
             
         }
            }
            //std::cout <<open.top();
        }
       // std::cout << ' ' << open.top();
        
        
       
    }
    



