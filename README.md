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

1. add - works. addEdge() generates an edge from node1 to node2 and from node2 to node1 given that the cost is greater than 0.
2. remove - works. removeEdge() remove the edge from node1 to node2 and from node2 to node1. If the edge does not exist nothing is done.
3. getCost - works. getCost() returns the cost from node1 to node2 and returns -1 if the edge does not exist.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - add will have two cases to consider when analyzing runtime. If the edge already exists we will have to loop through the edgeList of both node sto find the edge in order the update the value of the edge. This will take O(d) time. The second case is if the edge does not exist. Similiar to the first case we will have to cycle through the edgeLists of the nodes to determine that the edge is not already present. To do this the running time will have to be O(d) time. Because both of these are O(d) the worst case running time for add is O(d).
2. remove - similar to add the remove function will have to loop through the edgeLists. remove will loop through node1's edgeList to see if the there is an edge, if there is it will remove it and look through node2's edgeList. The worst case will be when we have to look through the whole edgeList to determine if there is an edge to delete. This will be done in O(d) time. So just like add, remove will be O(d) time. 
3. getCost - getCost will have to look through the edgeList of one of the nodes to determine if the edge exists. Because it has to look through the whole list the worst case running time will be O(d), so this will be the worst case running time for the function. 

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

Here it is: http://instagram.com/p/vjjlyXCxJg/

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I had trouble understanding the concept of adjList and edgeList to start, but once I overcome that, I was good to go. I would tell next years class to understand that concept and they will be ready for this assignment.