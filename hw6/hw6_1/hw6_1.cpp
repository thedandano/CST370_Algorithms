/*
 * Title: hw6_1.cpp
 * Abstract: This program implements radix sorting.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/10/2020
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define BASE 10

// prototypes
void print(vector<int> v);
vector<int> userInput();
int passesNeeded(vector<int> array);
void radixPass(vector<int> &array, int position);
void radixSort(vector<int> &array);


// main
int main()
{
    vector<int> array = userInput();
    radixSort(array);

    return 0;
}

/**
 * Prints a vector
 * @param vector<int> v the vector to be printed.
 */ 
void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * Returns an user fed vector.
 * @returns vector<int> input by the user.
 */ 
vector<int> userInput()
{
    vector<int> array;
    int len;

    cin >> len;
    array.resize(len);

    for (int x = 0; x < len; x++)
    {
        cin >> array[x];
    }

    return array;
}

/**
 * Calculates the passes needed for radix sort.
 * @param vector<int> to be assessed.
 * @returns passes needed for raddix sort
 */ 
int passesNeeded(vector<int> array)
{
    int digits;
    int max_digits = 0;
    for (int x = 0; x < array.size(); x++)
    {
        digits = 1;
        while (array[x] /= BASE)
        {
            digits++;
        }
        if (max_digits < digits)
            max_digits = digits;

    }
    return max_digits;
}

/**
 * Performs a single pass of the raddix sort algorithm.
 * @param vector<int> &array to be sorted 
 * @param int position the digit position to be sorted.
 */
void radixPass(vector<int> &array, int position)
{
    vector<vector<int>> buckets(BASE);
    vector<int> temp(array.size()); // used to store temp digit values (e.g., 79 -> 7)
    
    // Reduces the number by one positon (e.g., 79 becomes 7)
    for (int x = 0; x < array.size(); x++)
    {
        temp[x] = array[x] / pow(BASE, position);
    }

    // performs the non comparison sorting
    for (int x = 0; x < array.size(); x++)
    {
        buckets[temp[x] % BASE].push_back(array[x]);
    }

    array.clear(); // clears the vector in order to be refilled.

    // reloads the input array with the numbers in the buckets.
    for (int x = 0; x < buckets.size(); x++)
    {
        for (int y = 0; y < buckets[x].size(); y++)
        {
            if (buckets[x].size() > 0) 
                array.push_back(buckets[x][y]);
        }
    }
}

/**
 * Drives the radix sorting i.e., runs the raddix sort for x amount of passes.
 * @param vector<int> &array to be sorted
 */
void radixSort(vector<int> &array)
{
    int passes = passesNeeded(array);

    for (int x = 0; x < passes; x++)
    {
        radixPass(array, x);
        print(array); // prints each sort pass
    }
}


