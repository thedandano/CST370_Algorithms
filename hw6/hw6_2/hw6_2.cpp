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

        if (x > 1 && y > 1)
        {
            if (F[y - 1][x] > F[y][x - 1])
            {
                y--;
            }
            else
            {
                x--;
            }
        }
        else if (y > 1)
        {
            if (F[y - 1][x] >= F[y][x - 1])
                y--;
        }
        else if (x > 1)
        {
            if (F[y - 1][x] <= F[y][x - 1])
                x--;
        }
        else
        {
            break;
        }
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

int collectCoins(vector<vector<int>> &C, vector<vector<int>> &F)
{
    F[1, 1] = C[1, 1];

    // calculate first row
    for (int j = 2; j < F[0].size(); j++)
    {
        if (C[1][j] == BLOCKED)
        {
            F[1][j] = 0;
        }
        else
        {
            F[1][j] = F[1][j - 1] + C[1][j];
        }
    }

    // calculate remaining rows
    for (int i = 2; i < F.size(); i++)
    {
        if (C[i][1] == BLOCKED)
        {
            F[i][1] = 0;
        }
        else
        {
            F[i][1] = F[i - 1][1] + C[i][1];
        }

        for (int j = 2; j < F[0].size(); j++)
        {
            if (C[i][j] == BLOCKED)
            {
                F[i][j] = 0;
            }
            else
            {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
            }
        }
    }
    int row = C.size() - 1;
    int col = C[0].size() - 1;
    return F[row][col];
}

int main()
{
    vector<vector<int>> board = inputBoard();
    int width = board.size();
    int height = board[0].size();
    vector<vector<int>> F(width, vector<int>(height));
    cout << "\nMax coins:" << collectCoins(board, F) << endl;
    //print(F);
    getPath(F);
    return 0;
}
