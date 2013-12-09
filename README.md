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

1. add - add works as required, creating a new Edge and adding it to the correct edgeList; it also throws a string exception as required
2. remove - remove also works, setting the cost to -1 to represent the edge being removed
3. getCost - getCost works too

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - worst-case running time should be O(1), since everything in the method can be done in constant time
2. remove - worst-case running time should be O(d), since for each node, we loop through its edgeList to find one with the right dest
3. getCost - worst-case running time should be O(d), for the same reason as remove

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The number one thing I could possibly suggest is to NOT PROCRASTINATE.  Additionally, looking up vectors to figure out how they work a little bit is also helpful for this lab.