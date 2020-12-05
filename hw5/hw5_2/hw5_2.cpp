/*
 * Title: hw5_2.cpp
 * Abstract: This program tests the speed of heap sort, merge sort, and quick sort
 * using random numbers of an user defined size.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/4/20
 */

#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

// Prototypes
int userInput();
void print(int a[], int len);
void fillArray(int (&a)[], int len);
void heap_sort(int a[], int len);
void heapify(int (&heap)[], int len);
bool isMaxHeap(int (&heap)[], int len);
// void getTime(long long start, long long end, string testName);

int main()
{
    int len;
    cin >> len;
    int array[len];
    fillArray(array, len);

    cout << "===================== Execution Time ====================" << endl;
    auto start = chrono::steady_clock::now();
    // heap sort
    heap_sort(array, len);
    auto end = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed_time = end - start;
    cout << "Heap Sort"
         << ": " << elapsed_time.count() << " milliseconds" << endl;
    // }
    //getTime(start, end, "Heap Sort");

    start = chrono::steady_clock::now();
    // merge sort

    end = chrono::steady_clock::now();
    elapsed_time = end - start;
    cout << "Merge Sort"
         << ": " << elapsed_time.count() << " milliseconds" << endl;

    start = chrono::steady_clock::now();
    // // quick sort

    end = chrono::steady_clock::now();
    elapsed_time = end - start;
    cout << "Quick Sort"
         << ": " << elapsed_time.count() << " milliseconds" << endl;
    cout << "=========================================================" << endl;

    return 0;
}

// void getTime(long long start, long long end, string testName)
// {
//     chrono::duration<milliseconds> elapsed_time = end - start;
//     cout << testName << ": " << elapsed_time * 1000 << " milliseconds" << endl;
// }

void print(int a[], int len)
{
    for (int x = 1; x < len; x++)
    {
        cout << a[x] << " ";
    }
    cout << endl;
}

/**
 * Fills the array with random integers
 * @param int a[] array to be filled by reference
 * @param int len the length of the array to be filled
 */
void fillArray(int (&a)[], int len)
{
    for (int x = 0; x < len; x++)
    {
        a[x] = rand() % 1000; // generates a random number upper bound by the len of the array
    }
}

/**
 * Implements heap sort on an algorithm
 * @param int a[] array to be heap sorted
 */
void heap_sort(int a[], int len)
{
    int heap[len + 1];
    // copy array
    for (int x = 1; x < len + 1; x++)
    {
        heap[x] = a[x - 1];
    }

    heapify(heap, len + 1);
    int heap_sort[len + 1];
    for (int x = 1; x < len + 1; x++){
        heap_sort[x] = heap[x];
        heapify(heap, len + 1);
    }
    print(heap_sort, len + 1);
}

/**
 * Performs the heapify function on a heap
 * @param vector<int> &heap the heap to be heapified
 */
void heapify(int (&heap)[], int len)
{
    int parent;
    int currVal;
    bool is_heap;
    int l_child;
    int r_child;

    while (!isMaxHeap(heap, len))
    {
        for (parent = len / 2; parent > 0; parent--)
        {
            is_heap = false;
            l_child = 2 * parent;
            r_child = 2 * parent + 1;

            while (!is_heap && l_child < len)
            {

                if (l_child < len)
                {

                    if (heap[l_child] < heap[r_child])
                    {
                        l_child = r_child; // assignes right to left
                    }
                    if (heap[parent] >= heap[l_child])
                    {
                        is_heap = true;
                    }
                    else
                    {
                        // if parent is not greater than the left child
                        swap(heap[parent], heap[l_child]);
                    }
                }
            }
        }
    }
}

/**
 * Checks if a heap is a Max Heap.
 * @param vector<int> heap the heap to be checked
 * @returns a boolean value
 */
bool isMaxHeap(int (&heap)[], int len)
{
    int parent;
    int l_child;
    int r_child;
    for (int x = len / 2; x > 0; x--)
    {
        parent = x;
        l_child = x * 2;     // left child
        r_child = x * 2 + 1; // right child
        if (l_child < len)
        {
            //check left child
            if (heap[l_child] > heap[parent])
            {
                return false;
            }
        }
        if (r_child < len)
        {
            // check right child
            if (heap[r_child] > heap[parent])
            {
                return false;
            }
        }
    }
    return true;
}
