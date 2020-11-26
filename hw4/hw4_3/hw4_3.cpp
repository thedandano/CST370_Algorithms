/*
 * Title: hw4_3.cpp
 * Abstract: This program
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/25/2020
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// prototypes
vector<vector<int>> input();
vector<int> calcDegree(vector<vector<int>> g);
queue<int> loadQueue(vector<int> v);
void Kahn(vector<vector<int>> g);
void displayResults(vector<int> initDegree, vector<int> order);

int main() {
    vector<vector<int>> graph;
    graph = input();  // receives input
    Kahn(graph);
    return 0;
}

/**
 * Accepts user a user input graph
 * @returns vector<vector<int>> adjacency list.
 */
vector<vector<int>> input() {
    int vertices, edges;

    cin >> vertices;

    vector<vector<int>> graph;
    graph.resize(vertices);

    cin >> edges;
    int source, destination;
    for (int x = 0; x < edges; x++) {
        cin >> source >> destination;
        graph[source].push_back(destination);
    }

    // sort neighbors
    for (int x = 0; x < graph.size(); x++) {
        sort(graph[x].begin(), graph[x].end());
    }
    return graph;
}

/**
 * Performs Kahn's algorithm to perform topological sorting
 * @param vector<vector<int>> that represents the adjacency list of a graph.
 */
void Kahn(vector<vector<int>> g) {
    vector<int> degree;
    vector<int> initDegree;  // stores the initial degree values
    queue<int> q;
    vector<int> order;  // stores the visit order of the vertices.

    // calculate degree
    initDegree = calcDegree(g);
    degree = initDegree;
    // push zero degree vertex into queue
    q = loadQueue(degree);

    while (!q.empty()) {
        // remove vertex from queue
        int removed = q.front();
        order.push_back(removed);  // adds the removed to an order queue
        q.pop();

        // reduce neighbors by 1
        for (int x = 0; x < g[removed].size(); x++) {
            degree[g[removed][x]] -= 1;
            if (degree[g[removed][x]] == 0) {
                q.push(g[removed][x]);  // push next vertex with 0 degree.
            }
        }
    }
    displayResults(initDegree, order);
}

/**
 * Calculates the degree of each vertex
 * @param vector<vector<int>> g 
 * @returns vector<int> with the degrees of each vertex
 */
vector<int> calcDegree(vector<vector<int>> g) {
    vector<int> degree(g.size(), 0);

    for (int x = 0; x < g.size(); x++) {
        for (int y = 0; y < g[x].size(); y++) {
            degree[g[x][y]] += 1;
        }
    }

    return degree;
}

/**
 * Loads the queue with vertices with 0 degrees.
 * @param vector<int> v
 * @returns queue<int> with 0 degree vertices.
 */
queue<int> loadQueue(vector<int> v) {
    queue<int> q;
    for (int x = 0; x < v.size(); x++) {
        if (v[x] == 0) {
            q.push(x);
        }
    }
    return q;
}

/**
 * Displays the results of the Kahn Algorithm for topological ordering.
 * @param vector<int> initDegree 
 * @param vector<int> order
 */
void displayResults(vector<int> initDegree, vector<int> order) {
    // print the degree
    for (int x = 0; x < initDegree.size(); x++) {
        cout << "In-degree[" << x << "]:" << initDegree[x] << endl;
    }

    // check for cycles
    if (order.size() == initDegree.size()) {
        cout << "Order:" << order[0];
        for (int x = 1; x < order.size(); x++) {
            cout << "->" << order[x];
        }
        cout << endl;
    } else {
        cout << "No Order:" << endl;
    }
}
