/*
 * Title: hw6_2.cpp
 * Abstract: This program simulates the collection of the maximum value of coins
 * on a board of n x m dimensions.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/12/2020
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * Struct to hold results of coin collection
 * int max holds the max value of coins
 * vector<vector<int>> valueBoard hold the calculated board values.
 */
struct coinResults {
    int max;
    vector<vector<int>> valueBoard;
};

#define BLOCKED 2
#define NEW_BLOCKED -1
void print(vector<vector<int>> B);
vector<vector<int>> inputBoard();
coinResults collectCoins(vector<vector<int>> C);
int max(int a, int b);
vector<pair<int, int>> getPath(vector<vector<int>> F);
void printPath(vector<pair<int, int>> path);

int main() {
    // input board
    vector<vector<int>> board = inputBoard();
    coinResults r = collectCoins(board);

    // Diag
    // cout << "Cost: " << endl;
    // print(r.valueBoard);

    // print results
    cout << "Max coins:" << r.max << endl;
    printPath(getPath(r.valueBoard));

    return 0;
}

/**
 * Prints the 2D vector. This is just for diag.
 * @param vector<vector<int>> B
 */
void print(vector<vector<int>> B) {
    for (int x = 1; x < B.size(); x++) {
        for (int y = 1; y < B[x].size(); y++) {
            cout << B[x][y] << " ";
        }
        cout << endl;
    }
}

/**
 * Receives user input data for the board.
 * @returns vector<vector<int>> 
 */
vector<vector<int>> inputBoard() {
    vector<vector<int>> B;
    int height, width;

    // input dimensions
    cin >> height >> width;
    height++;
    width++;
    B.resize(width, vector<int>(height));

    //input data
    for (int x = 1; x < B.size(); x++) {
        for (int y = 1; y < B[x].size(); y++) {
            cin >> B[x][y];
        }
    }
    return B;
}

/**
 * Performs calculates the values of the board using dynamic programming
 * @param vector<vector<int>> &C the board with coins.
 * @returns coinResults containing max value of coins and 2D vector containing calculated values.
 */
coinResults collectCoins(vector<vector<int>> C) {
    int width = C.size();
    int height = C[0].size();
    vector<vector<int>> F(width, vector<int>(height));

    F[1, 1] = C[1, 1];

    // calculate first row
    for (int j = 2; j < F[0].size(); j++) {
        if (C[1][j] == BLOCKED) {
            F[1][j] = NEW_BLOCKED;
        } else {
            // creates a blocked area if the last cell is blocked
            if (F[1][j - 1] == NEW_BLOCKED)
                F[1][j] = NEW_BLOCKED;
            else
                F[1][j] = F[1][j - 1] + C[1][j];
        }
    }

    // calculate remaining rows
    for (int i = 2; i < F.size(); i++) {
        // looks at cell above
        if (C[i][1] == BLOCKED) {
            F[i][1] = NEW_BLOCKED;
        } else {
            // creates a blocked area below if the top cell is blocked.
            if (F[i - 1][1] == NEW_BLOCKED)
                F[i][1] = NEW_BLOCKED;
            else
                F[i][1] = F[i - 1][1] + C[i][1];
        }

        // looks at the cell before and above
        for (int j = 2; j < F[0].size(); j++) {
            if (C[i][j] == BLOCKED) {
                F[i][j] = NEW_BLOCKED;
            } else {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
            }
        }
    }

    // returns the last row and last cell which is the max value and the calculated values board.
    int row = C.size() - 1;
    int col = C[0].size() - 1;
    coinResults r;
    r.max = F[row][col];
    r.valueBoard = F;
    return r;
}

/**
 * Returns the max value of two numbers.
 * @return int max
 */
int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

/**
 * Calculates the path to collect the ax amount of coins.
 * @param vector<vector<int>> a calculated board.
 * @returns vector<pair<int,int>> which contains the path (backwards).
 */
vector<pair<int, int>> getPath(vector<vector<int>> F) {
    vector<pair<int, int>> path;
    int x = F[0].size() - 1;
    int y = F.size() - 1;

    while (true) {
        path.push_back(make_pair(x, y));  // adds current node to path.

        if (x > 1 && y > 1) {
            if (F[y - 1][x] > F[y][x - 1]) {
                y--;
            } else {
                x--;
            }
        } else if (y > 1) {  // this occurs if x axis is at limit
            if (F[y - 1][x] >= F[y][x - 1])
                y--;
        } else if (x > 1) {  // this occurs if y axis is at limit
            if (F[y - 1][x] <= F[y][x - 1])
                x--;
        } else {
            break;
        }
    }
    return path;
}

/**
 * Prints the path 
 * @param vector<pair<int,int>> path
 */
void printPath(vector<pair<int, int>> path) {
    cout << "Path:"
         << "(" << path[path.size() - 1].first
         << "," << path[path.size() - 1].second << ")";

    for (int x = path.size() - 2; x >= 0; x--) {
        cout << "->"
             << "(" << path[x].first
             << "," << path[x].second << ")";
    }
    cout << endl;
}
