08_Graph_Lab
============

Implement a simple graph class

Requirements
------------

1. Implement all methods of the `Graph` class.

Reading
=======
"Open Data Structures," Chapter 12, the whole chapter. http://opendatastructures.org/ods-cpp/12_Graphs.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. add - I think add works, though I had trouble testing the exception throwing.  I also threw exceptions if the nodes were not in the graph, which was not required but I felt that it could be an issue.
2. remove - I think remove works. It looks through the edgeLists of the nodes to find the edge that goes to the other node, erases that edge, and then returns. 
3. getCost - I think getCost works because it looks through node1's edgeList to find an edge that goes to node2 and returns the cost of that edge. If there is no edge, it will return -1.0.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - addEdge has two cases: if the edge already exists, or if a new edge must be made. In the first case, we end up looking through the edgeLists of both nodes in question to find the edge that exists in order to update its cost. In the worst case, each of these nodes would have d edges (the maximum degree of any node in the graph). Therefore, we would look thorugh 2d spaces in the vector, so the running time would be O(d). In the second case where we must make new edges, we still have to check to see if an edge already exists. Since no edge exists, we will end up looking through all the edges for one of the nodes. In the worst case, this takes O(d) time. However, to create an edge I used the push_back function in the vector class. After reading a bit about it, it would appear that at worst this function has to move all the elements to a new array, which would take O(d) time in the worst case (if the node we are adding the edge to has d edges). Since we do this twice, the total running time would be d + d + d = 3d, so the running time for the second case is O(d). Therefore, since the worst-case running times for both cases of addEdge equal O(d), the worst case running time for addEdge is O(d). 
2. remove - remove looks through all the edges in the first node's edgeList to see if there is an edge to erase. If there is, it erases that edge and then looks through the edgeList of node2 to find the edge and erase it. In the worst case, where there is an edge and it is at the back of the edgeList vector, we will have to look through at most d edges. We also need to take into account the runtime for vector's erase function. I think in the worst case this function will have to shift all the elements in the backing array for the vector. The edgeList vector will at worst have d elements. This is performed twice (once for each node) so the total running time would be d + d + d + d = 4d (2d from looking through all the nodes in two edgeLists, and another 2d for erasing twice). Therefore, the worst-case running time for remove would be O(d). 
3. getCost - getCost has to look through all the edges in edgeList for one node, and then just returns the cost for that edge. Unlike addCost and remove, it only has to look through one of the node's edgeLists since the edge cost will be no different in the different edgeLists. At worst, looking through one edgeList will take O(d) time, so this is the worst-case running time for getCost. 

TODO

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.
#####Adjacency Matrix
| Node  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:-----:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| **0** | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 
| **1** | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 
| **2** | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 0 | 
| **3** | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 
| **4** | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 
| **5** | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 
| **6** | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 
| **7** | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 
| **8** | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 
| **9** | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 
#####Adjacency List
An adjacency list has one list of the nodes, where each node points to a List of the other nodes it shares an edge with.  http://instagram.com/p/vUsqmwOPN0/  (PS this is my roommate's Instagram, just to warn you.)

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The hardest part for me was figuring out how to use and think about the vector class.  I kept getting a lot of syntax errors. Students next semester: read about vectors before attempting to use them!