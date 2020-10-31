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

    for (int x = 0; x < numEvents; x++) {
        cin >> start >> end;
        for (int y = 0; y < hours; y++) {
            if (y >= start && y < end) {
                eventArr[x][y] = 1;
            } else {
                eventArr[x][y] = 0;
            }
        }
    }

    int count = 0;
    int max = 0;
    for (int y = 0; y < hours; y++) {
        for (int x = 0; x < numEvents; x++) {
            if (eventArr[x][y] == 1) {
                count++;
            }
        }
        // set max
        if (count > max) {
            max = count;
        }
        //reset count
        count = 0;
    }
    cout << "Max events:" << max << endl;

    return 0;
}