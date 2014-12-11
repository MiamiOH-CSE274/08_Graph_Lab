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

1. add - Works. Adds an edge with an associated cost provided the cost is valid.
2. remove - Works. Removes an edge if an edge exists.
3. getCost - I get an error saying "Expected edge cost of -1, but got -1" which makes no sense so I think it works. 

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - Two cases exist(loop through and update cost / loop through without finding edge->create edge), but for both cases we have to loop through the edgelist which, at worst-case, is 0(d).
2. remove - Like add, if we have to loop through the edgelist the worst-case is 0(d). Even if there are no edges, we have to loop through, which means run times are always close to 0(d).
3. getCost - We can find the cost in the first few searches, but in the worst-case the run time is still 0(d) due to the possibility of having to loop through the whole edgelist.

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

http://imgur.com/IG8gRcx

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
I had trouble with adjList. At first I tried to do adjList = .... in the contructor which caused a lot of errors until I figured out that I just had to resize it.
