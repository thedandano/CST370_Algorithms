### Homework 4

#### [Homework 4_1](./hw4_1)

This program partitions a set of numbers by putting all negative numbers in the front and the positive numbers in the rear. Not ordered.
##### Sample input:
* First input indicates the set size
* The remaining values are the set

```
8 
-4 3 9 -6 2 -5 8 7 
```

##### Sample output:

```
-4 -5 -6 9 2 3 8 7 
-4 -6 -5 3 2 9 8 7 
```

#### [Homework 4_2](./hw4_2)

Reads user input graph data then presents a path for the traveling salesman problem.

##### Sample input:

- First input indicates number of vertices
- Second input indicates number of edges (N inputs)
- N inputs are input in as (Source, Destination, Weight)
- Last input indicates the starting vertex

```
4
12
0 1 2
0 3 7
0 2 5
1 0 2
1 2 8
1 3 3
2 0 5
2 1 8
2 3 1
3 0 7
3 1 9
3 2 1
0
```

##### Sample output:

```
Path:0->1->3->2->0
Cost:11
```

#### [Homework 4_3](./hw4_3)

This program implements the Depth-First Search algorithm and outputs the order of visited vertices.

##### Sample input:

- First input indicates number of vertices
- Second input indicates number of edges
- Remaining inputs are input as (Source, Destination)

```
5
6
0 1
0 2
0 3
1 3
2 3
3 4
```

##### Sample output:

```
Mark[0]:1
Mark[1]:2
Mark[2]:5
Mark[3]:3
Mark[4]:4
```
