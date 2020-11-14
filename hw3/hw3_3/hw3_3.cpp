/*
 * Title: hw
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

// Global Var
//int counter = 0;  // tracks the order of node visited

int main() {
    vector<vector<int>> graph;
    vector<int> mark;
    int start = 0;

    graph = userInput();

    mark.resize(graph.size(), 0);  // resizes to mark vector to match graph's size
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
    int curr = 0;
    int counter = 0;
    dfs(g, m, curr, counter);
}

/**
 * Implements the Depth-First Search Algorithm
 * @param vector<vector<int>> g the graph to be searched.
 * @returns vector<int> mark which records the order of traversed vertices.
 */
void dfs(vector<vector<int>> g, vector<int> &m, int curr, int &counter) {
    m[curr] = ++counter;
    for (int x = 0; x < g[curr].size(); x++) {
        int neighbor = g[curr][x];
        if (m[neighbor] == 0) {
            dfs(g, m, neighbor, counter);
        }
    }
}

/**
 * Prints out the mark vector
 * @param vector<int> m input
 */
void printMark(vector<int> m) {
    for (int x = 0; x < m.size(); x++) {
        cout << "Mark[" << x << "]:" << m[x] << endl;
    }
}
