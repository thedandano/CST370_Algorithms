/*
 * Title: hw6_2.cpp
 * Abstract: This program simuates the collection of the maximum value of coins
 * on a board of n x m dimentions.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/12/2020
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define BLOCKED 2

void print(vector<vector<int>> B)
{
    for (int x = 1; x < B.size(); x++)
    {
        for (int y = 1; y < B[x].size(); y++)
        {
            cout << B[x][y] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> inputBoard()
{
    vector<vector<int>> B;
    int height, width;

    // input dimentions
    cin >> height >> width;
    height++;
    width++;
    B.resize(width, vector<int>(height));

    //input data
    for (int x = 1; x < B.size(); x++)
    {
        for (int y = 1; y < B[x].size(); y++)
        {
            cin >> B[x][y];
        }
    }
    return B;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void getPath(vector<vector<int>> F)
{
    vector<pair<int, int>> path;
    int x = F[0].size() - 1;
    int y = F.size() - 1;

    while (true)
    {
        path.push_back(make_pair(x, y));

        if (y > 0)
        {
            if (F[y - 1][x] > F[y][x - 1])
                y--;
        }
        if (x > 0)
        {
            if (F[y][x - 1] > F[y - 1][x])
                x--;
        }
        if (y == 1 && y == 1)
            break;
        // if (F[y - 1][x] > F[y][x - 1])
        // {
        //     y--;
        // }
        // else
        // {
        //     x--;
        // }
    }

    cout << "Path:"
         << "(" << path[path.size() - 1].first
         << "," << path[path.size() - 1].second << ")";

    for (int x = path.size() - 2; x >= 0; x--)
    {
        cout << "->"
             << "(" << path[x].first
             << "," << path[x].second << ")";
    }
    cout << endl;
}

int collectCoins(vector<vector<int>> C, vector<vector<int>> &F)
{
    F.resize(C.size(), vector<int>(C[0].size()));
    F[1, 1] = C[1, 1];
    for (int j = 2; j < F[j].size(); j++)
    {
        if (F[1][j] == BLOCKED)
        {
            F[1][j] = -1;
            continue;
        }
        F[1][j] = F[1][j - 1] + C[1][j];
    }
    for (int i = 2; i < F.size(); i++)
    {
        F[i][1] = F[i - 1][1] + C[i][1];
        for (int j = 2; j < F[i].size(); j++)
        {
            if (C[i][j] == BLOCKED)
            {
                F[i][j] = -1;
            }
            else
            {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
            }
        }
    }
    return F[C.size() - 1][C[0].size() - 1];
}

int main()
{
    vector<vector<int>> board = inputBoard();

    vector<vector<int>> F;
    // cout << "\nBoard" << endl;
    // cout << "----------" << endl;
    //print(board);
    // cout << "----------" << endl;
    cout << "\nMax coins:" << collectCoins(board, F) << endl;
    // print(F);
    getPath(F);

    return 0;
}
