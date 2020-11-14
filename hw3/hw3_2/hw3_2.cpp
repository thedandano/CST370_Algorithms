/*
 * Title: hw3_3.cpp
 * Abstract: This program solves the Traveling Salesman Problem. It takes in 
 * user graph data then it presents the most shortest round trip path.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 11/12/2020
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Stores the edges
struct edge {
    int destination, cost;
};
//Stores the results
struct results {
    vector<int> p;
    int cost;
};

// Prototypes
void readInput(vector<vector<edge>> &graph, int &start_vertex, vector<int> &p);
int getCost(vector<vector<edge>> g, int start_vertex, vector<int> &p);
results findOptimalPath(vector<vector<edge>> g, int start_vertex, vector<int> &p);
void printResults(results r);

int main() {
    vector<vector<edge>> graph;  // stores user data as a graph
    vector<int> p;               // a helper vector which is permutated and then used as a key to find the optimal path.
    results r;                   // stores the results
    int start_vertex;

    readInput(graph, start_vertex, p);
    r = findOptimalPath(graph, start_vertex, p);
    printResults(r);

    return 0;
}

/**
 * Reads user input and updates the graph, start curr, and the permutation vector
 * @param vector<vector<edge>> graph is passed by reference to and is updated by function
 * @param int start_vertex is passed by reference and updated 
 * @param vector<int> p is passed by reference and is updated
 * 
 */
void readInput(vector<vector<edge>> &graph, int &start_vertex, vector<int> &p) {
    int vertices, edges;
    cin >> vertices;

    // resize graphs
    graph.resize(vertices);
    p.resize(vertices);

    // load permutation array
    for (int x = 0; x < p.size(); x++) {
        p[x] = x;
    }

    // intake edge data from user
    int source, destination, cost;
    edge e;
    cin >> edges;
    for (int x = 0; x < edges; x++) {
        cin >> source >> destination >> cost;
        e.destination = destination;
        e.cost = cost;
        graph[source].push_back(e);
    }
    // instake starting curr
    cin >> start_vertex;
}

/**
 * calculates the cost of each permutation and returns the cost.
 * @param vector<vector<edge>> g is used to extract cost from
 * @param int start_vertex is used as the starting and ending point
 * @param vector<int> p is used as the order of traversing the graph.
 * @returns the cost of the passed permutation
 */
int getCost(vector<vector<edge>> g, int start_vertex, vector<int> &p) {
    int cost = 0;
    int counter = 0;

    if (p[0] == start_vertex) {
        p.push_back(start_vertex);  // adds the starting vertex to the end

        int curr;
        int next;
        // iterates the p vector
        for (int x = 0; x < p.size() - 1; x++) {
            curr = p[x];
            next = p[x + 1];
            // looks for the next vertex in the nested vector.
            for (int y = 0; y < g[curr].size(); y++) {
                if (g[curr][y].destination == next) {
                    cost += g[curr][y].cost;
                    counter++;
                }
            }
        }
        p.pop_back();  // removes the last vertex, otherwise the next permutation will use this value too.
    }
    // if the amount of vertices visited is less than the amount of vertices then there is no path.
    if (counter < p.size()) {
        return -1;
    }
    return cost;
}

/**
 * Finds the optimal path for the TSP.
 * @param vector<vector<edge>> g represents the user input graph
 * @param int start_vertex the starting and ending point
 * @param vector<int> p 
 * @returns the results of the optimal path.
 */
results findOptimalPath(vector<vector<edge>> g, int start_vertex, vector<int> &p) {
    int cost = 0;
    int minCost = numeric_limits<int>::max();  // maximum value of a signed int
    results r;
    do {
        cost = getCost(g, start_vertex, p);
        // stores the optimal path in a structure
        if (cost < minCost && cost > 0) {
            minCost = cost;
            r.p = p;
            r.p.push_back(start_vertex);
            r.cost = cost;
        }
    } while (next_permutation(p.begin(), p.end()));

    // if the minCost is not modified then there must be no path.
    if (minCost == numeric_limits<int>::max()) {
        r.cost = -1;
    }

    return r;
}
/**
 * Prints the results of the optimal path.
 * @param results r 
 */
void printResults(results r) {
    cout << "Path:";
    if (r.p.size() > 0) {
        cout << r.p[0];
        for (int x = 1; x < r.p.size(); x++) {
            cout << "->" << r.p[x];
        }
    }
    cout << endl;
    cout << "Cost:" << r.cost << endl;
}