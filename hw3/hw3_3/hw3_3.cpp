/*
 * Title: hw3_3.cpp
 * Abstract: This program implements the Depth-First Search algorithm to traverse
 * a user input graph.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/13/2020
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Prototypes
vector<vector<int>> userInput();
void startTraversal(vector<vector<int>> g, vector<int> &m);
void dfs(vector<vector<int>> g, vector<int> &m, int curr, int &counter);
void printMark(vector<int> m);

int main() {
    vector<vector<int>> graph;
    vector<int> mark;
    int start = 0;

    graph = userInput();

    startTraversal(graph, mark);
    printMark(mark);

    return 0;
}

/**
 * Intakes user input
 * @returns vector<vector<int>> that represents a graph based on user input.
 */
vector<vector<int>> userInput() {
    vector<vector<int>> g;
    int vertices, edges;

    cin >> vertices;
    g.resize(vertices);

    cin >> edges;
    int source, destination;
    for (int x = 0; x < edges; x++) {
        cin >> source >> destination;
        g[source].push_back(destination);
    }

    // sorts neighboring nodes inside vector in ascending order
    for (int x = 0; x < vertices; x++) {
        sort(g[x].begin(), g[x].end());
    }

    return g;
}

/**
 * Readies variables to start traversal of graph.
 * @param vector<vector<int>> g represents the graph to be traversed
 * @param vector<int> &m is the mark array passed in by reference.
 */
void startTraversal(vector<vector<int>> g, vector<int> &m) {
    int start = 0;          // the starting node
    int counter = 0;        // tracks the order each node was visited in
    m.resize(g.size(), 0);  // resizes to mark vector to match graph's size
    dfs(g, m, start, counter);
}

/**
 * Implements the Depth-First Search Algorithm
 * @param vector<vector<int>> g the graph to be searched.
 * @returns vector<int> mark which records the order of traversed vertices.
 */
void dfs(vector<vector<int>> g, vector<int> &m, int curr, int &counter) {
    m[curr] = ++counter;  // marks the current node with order it was visited in.

    for (int x = 0; x < g[curr].size(); x++) {  // checks the currents nodes neighbors
        int neighbor = g[curr][x];
        if (m[neighbor] == 0) {  // if neighbor has not been visited, lets visit!
            dfs(g, m, neighbor, counter);
        }
    }
}

/**
 * Prints out the mark vector
 * @param vector<int> m the mark array to be printed out.
 */
void printMark(vector<int> m) {
    for (int x = 0; x < m.size(); x++) {
        cout << "Mark[" << x << "]:" << m[x] << endl;
    }
}
