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

struct edge {
    int destination, cost;
};
struct results {
    vector<int> p;
    int cost;
};

void testPrint(vector<vector<edge>> graph, int start_index);
void readInput(vector<vector<edge>> &graph, int &start_vertex, vector<int> &p);
void printPermute(vector<int> &p);
int getCost(vector<vector<edge>> g, int start_vertex, vector<int> &p);
results findOptimalPath(vector<vector<edge>> g, int start_vertex, vector<int> &p);
void printResults(results r);

int main() {
    vector<vector<edge>> graph;
    vector<int> p;
    results r;
    int start_vertex;

    readInput(graph, start_vertex, p);
    r = findOptimalPath(graph, start_vertex, p);
    printResults(r);

    return 0;
}

void testPrint(vector<vector<edge>> graph, int start_index) {

    for (int x = 0; x < graph.size(); x++) {
        cout << "V:" << x;

        for (int y = 0; y < graph[x].size(); y++) {
            cout << " (" << graph[x][y].destination;
            cout << "," << graph[x][y].cost << ")";
        }

        cout << endl;
    }
    cout << "S:" << start_index << endl;
}

void readInput(vector<vector<edge>> &graph, int &start_vertex, vector<int> &p) {
    int vertices, edges;
    cin >> vertices;

    graph.resize(vertices);
    p.resize(vertices);

    for (int x = 0; x < p.size(); x++) {
        p[x] = x;
    }

    int source, destination, cost;
    edge e;
    cin >> edges;
    for (int x = 0; x < edges; x++) {
        cin >> source >> destination >> cost;
        e.destination = destination;
        e.cost = cost;
        graph[source].push_back(e);
    }
    cin >> start_vertex;

}

void printPermute(vector<int> &p) {
    for (int x = 0; x < p.size(); x++) {
        cout << p[x] << "";
    }
    cout << endl;
}

int getCost(vector<vector<edge>> g, int start_vertex, vector<int> &p) {
    int sum = 0;
    int counter = 0;

    if (p[0] == start_vertex) {
        p.push_back(start_vertex);

        int vertex;
        int next;
        int complete = true;
        for (int x = 0; x < p.size() - 1; x++) {
            vertex = p[x];
            next = p[x + 1];

            for (int y = 0; y < g[vertex].size(); y++) {
                if (g[vertex][y].destination == next) {
                    sum += g[vertex][y].cost;
                    counter++;
                }
            }
        }
        p.pop_back();
    }
    if (counter < p.size()) {
        return -1;
    }
    return sum;
}

results findOptimalPath(vector<vector<edge>> g, int start_vertex, vector<int> &p) {
    int cost = 0;
    int minCost = 0x7FFFFFFF;
    results r;
    do {
        // printPermute(p);
        cost = getCost(g, start_vertex, p);

        if (cost < minCost && cost > 0) {
            minCost = cost;
            r.p = p;
            r.p.push_back(start_vertex);
            r.cost = cost;
        }
    } while (next_permutation(p.begin(), p.end()));
    if (minCost == 0x7FFFFFFF) {
        r.cost = -1;
    }

    return r;
}
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