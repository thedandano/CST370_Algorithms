### Homework 3

#### [Homework 3_1](./hw3_1)

This program reads a positive integer from the user and reverses it while removing any leading zeros.

##### Sample input:

```
1200
```

##### Sample output:

```
21
```

#### [Homework 3_2](./hw3_2)

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

#### [Homework 3_3](./hw3_3)

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
