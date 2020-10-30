/*
 * Title: hw1_1.cpp
 * Abstract: This program reads inputs from the user and displays the closest
 * distance between two numbers among all input numbres.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 10/29/2020
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// function prototypes
void sortDecend(int arr[], int arrLen);
void getMinDistance(int arr[], int arrLen);

int main()
{
    int numbersIn = 0;
    cin >> numbersIn;

    int numbers[numbersIn];
    for (int x = 0; x < numbersIn; x++)
    {
        cin >> numbers[x];
    }

    sortDecend(numbers, numbersIn);

    cout << endl;

    getMinDistance(numbers, numbersIn);

    return 0;
}

/**
 * Sorts the array in decending order
 * @param int array[]
 * @param int arrLen
 */
void sortDecend(int arr[], int arrLen)
{
    int temp;

    for (int x = 0; x < arrLen; x++)
    {
        for (int y = 0; y < arrLen; y++)
        {
            if (arr[x] > arr[y])
            {
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }
}

/**
 * Calculates the minimum distane between 2 numbers and prints the min disantce
 * and which two numbers.
 * @param int arr[]
 * @param int arrLen
 */
void getMinDistance(int arr[], int arrLen)
{
    // initializes with first a distance of first two numbers
    int firstNumber = arr[0];
    int secondNumber = arr[1];
    int distance = arr[0] - arr[1];
    int tempDis;

    for (int x = 0; x < arrLen; x++)
    {
        for (int y = 0; y < arrLen; y++)
        {
            tempDis = arr[y] - arr[x];

            // only takes positive numbers and if less than current distance
            if (tempDis > 0 && tempDis < distance)
            {
                distance = tempDis;
                firstNumber = arr[y];
                secondNumber = arr[x];
            }
        }
    }
    cout << "Min distance: " << distance << endl;
    cout << "Two numbers for min distance: " << secondNumber << " and " << firstNumber << endl;
}