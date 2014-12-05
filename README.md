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

1. add - add correctly addes two edge objects, one to both vector of each node
2. remove - removes the edge between the two nodes if it exists
3. getCost - returns the cost of the edge if it exists, -1.0 if it doesnt

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - O(1) new values are simple added to the back of the vectors
2. remove - O(d) because only the edges for a specific node are looked at to find a match
3. getCost - O(d) save as remove


#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

http://a.pomf.se/vbnxvn.png

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

start learning some of the stl algorithm methods, they are very usefull (this advice isnt really specific toward this porject, but to c++ in general)
