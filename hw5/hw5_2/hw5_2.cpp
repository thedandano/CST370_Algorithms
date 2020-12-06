/*
 * Title: hw5_2.cpp
 * Abstract: This program tests the speed of heap sort, merge sort, and quick sort
 * using random numbers of an user defined size.
 * Credits: The heap sort, merge sort, and quick sort algorithms are coutesy of 
 * geeksforgeeks.com
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/4/20
 */

#include <chrono>
#include <iomanip>
#include <iostream>
// global
#define text_width 12  // print formatting

using namespace std;

// Prototypes
int userInput();
void print(int a[], int len, int startFrom);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main() {
    int len;
    cin >> len;
    int *array = new int[len];

    // fillArray with random numbers
    srand(time(0));  // seed the random number generator
    for (int x = 0; x < len; x++) {
        array[x] = rand() % len;  // generates a random number upper bound by the len of the array
    }

    // create copies of arrays
    int *mergeSortArr = new int[len];
    int *quickSortArr = new int[len];
    for (int x = 0; x < len; x++) {
        mergeSortArr[x] = array[x];
        quickSortArr[x] = array[x];
    }

    cout << "===================== Execution Time ====================" << endl;

    // heap sort
    auto start = chrono::steady_clock::now();
    heapSort(array, len);
    auto end = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed_time = end - start;
    cout << left << setw(text_width) << "Heap Sort: "
         << elapsed_time.count()
         << right << " milliseconds" << endl;

    // merge sort
    start = chrono::steady_clock::now();
    mergeSort(mergeSortArr, 0, len - 1);
    end = chrono::steady_clock::now();
    elapsed_time = end - start;
    cout << left << setw(text_width) << "Merge Sort: "
         << elapsed_time.count()
         << right << " milliseconds" << endl;

    // quick sort
    start = chrono::steady_clock::now();
    quickSort(quickSortArr, 0, len - 1);
    end = chrono::steady_clock::now();
    elapsed_time = end - start;
    cout << left << setw(text_width) << "Quick Sort: "
         << elapsed_time.count()
         << right << " milliseconds" << endl;

    cout << "=========================================================" << endl;

    return 0;
}

//print for diag purposes
void print(int a[], int len, int startFrom) {
    for (int x = startFrom; x < len; x++) {
        cout << a[x] << " ";
    }
    cout << endl;
}

// /**
//  * Fills the array with random integers
//  * @param int a[] array to be filled by reference
//  * @param int len the length of the array to be filled
//  */
// void fillArray(int (&a)[], int len) {
//     srand(time(0));  // seed the random number generator
//     for (int x = 0; x < len; x++) {
//         a[x] = rand() % len;  // generates a random number upper bound by the len of the array
//     }
// }

/*******************************************************************************
*                                  Heap Sort                                   *
*                            From Geeksforgeeks.com                            *
 *******************************************************************************/

// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i;    // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

/*******************************************************************************
*                                  Merge Sort                                  *
*                            From Geeksforgeeks.com                            *
 *******************************************************************************/

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int *L = new int[n1];
    int *R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete L;
    delete R;
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;  //returns recursively
    }
    int m = (l + r - 1) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

/*******************************************************************************
*                                  Quick Sort                                  *
*                            From Geeksforgeeks.com                            *
 *******************************************************************************/
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;  // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
