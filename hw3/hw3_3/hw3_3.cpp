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

void printList(vector<vector<int>> g);
vector<vector<int>> userInput();
void startTraversal(vector<vector<int>> g, vector<int> &m);
void dfs(vector<vector<int>> g, vector<int> &m, int &count);
void printMark(vector<int> m);
void printAll(vector<vector<int>> g, vector<int> m) {
    printList(g);
    cout << endl;
    printMark(m);
}

int main() {
    vector<vector<int>> graph;
    vector<int> mark;
    int start = 0;

    graph = userInput();
    //    printList(graph);

    mark.resize(graph.size(), 0);
    startTraversal(graph, mark);
    //printMark(mark);
    printAll(graph, mark);

    return 0;
}

void printList(vector<vector<int>> g) {
    for (int x = 0; x < g.size(); x++) {
        cout << x;
        for (int y = 0; y < g[x].size(); y++) {
            cout << "->" << g[x][y];
        }
        cout << endl;
    }
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

    for (int x = 0; x < vertices; x++) {
        sort(g[x].begin(), g[x].end());
    }

    return g;
}

void startTraversal(vector<vector<int>> g, vector<int> &m) {
    int count = 0;
    dfs(g, m, count);
}

/**
 * Implements the Depth-First Search Algorithm
 * @param vector<vector<int>> g the graph to be searched.
 * @returns vector<int> mark which records the order of traversed vertices.
 */
void dfs(vector<vector<int>> g, vector<int> &m, int &count) {
    m[count] = count + 1;
    for (int x = 0; x < g[count].size(); x++) {
        int neighbor = g[count][x];
        if (m[neighbor] == 0) {
            cout << "neighbor" << neighbor << endl;

            dfs(g, m, neighbor);
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
