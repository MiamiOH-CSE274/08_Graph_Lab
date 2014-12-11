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

1. add - Add works. It checks if cost is negative, if so it throws an exception, otherwise it checks to see if there is already a similar/exact edge (then the cost is updated). After checking through the data, it will add edges if it doesn't find duplicates.
2. remove - Also runs. It runs through to see if an edge from node1 to node2 exists, and deletes it (overwrites it with nothing) if it does. If there isn't an edge, then  nothing happens.
3. getCost - getCost goes through the list looking for an existing edge from node1 to node2, and if it exists, returns the cost. Otherwise it returns -1.0 (which means it didn't find an edge).

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - Best (running time) case scenario is that cost is less than 0 so we just throw an exception. AddEdge has to check the list for existing edges, so it would be O(d) even though updating data would be constant. Adding data would be linear time, but since O(d) is worse/slows it down, that's the one we'll use.
2. remove - removeEdge is similar to add, it has to loop through the data to check if an edge exists. So the running time is O(d).
3. getCost - getCost also requires looping through edgeList, so it's time is also O(d).

TODO

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.
http://imgur.com/bAOauzL

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Knowing about class shortcuts always help (like resize instead of making a whole new list).