/*
 * Title: hw1_3.cpp
 * Abstract: This program takes in a set of events and displays the maximum
 * number of events that can take place concurrently.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 10/30/2020
 */

#include <iostream>
using namespace std;

int main() {
    int numEvents;
    cin >> numEvents;

    int hours = 24;
    int eventArr[numEvents][hours];
    int start, end;

    // Fills an array based on user input.
    for (int x = 0; x < numEvents; x++) {
        cin >> start >> end;
        for (int y = 0; y < hours; y++) {
            if (y >= start && y <= end) {
                eventArr[x][y] = 1;
            } else {
                eventArr[x][y] = 0;
            }
        }
    }

    //sums the the columns to determin concurrency of events.
    int count = 0;
    int max = 0;
    for (int y = 0; y < hours; y++) {
        for (int x = 0; x < numEvents; x++) {
            if (eventArr[x][y] == 1) {
                count++;
            }
        }
        // updates max value as condition is met.
        if (count > max) {
            max = count;
        }
        //reset count
        count = 0;
    }
    cout << "Max events:" << max << endl;
    return 0;
}
