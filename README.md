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

1. add - add works by creating the bond between node 1 and node 2 then node 2 and node 1.
2. remove - remove works by deleting the bond between node 1 and node 2 then node 2 and node 1.
3. getCost - getCost works by finding the edge between node 1 and node 2 then returning the cost.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - 2m if the second node in each pair is the last combination to be checked.
2. remove - 2m if the second node in each pair is the last combination to be checked.
3. getCost - m if there is no edge between the pair of nodes.

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

0	2 3 5
1	3 4 6
2	0 4 7
3	0 1 8
4	1 2 9
5	0 6 9
6	1 5 7
7	2 6 8
8	3 7 9
9	4 5 8

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Vectors, while not very difficult, were new to me.