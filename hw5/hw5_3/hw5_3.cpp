/*
 * Title: hw5_3.cpp
 * Abstract: This program simulates the operations of linear probing.
 * Author: Dan Sedano
 * ID: 0254
 * Date: 12/5/2020
 */

#include <iostream>
#include <vector>
using namespace std;

#define LOAD 0.5    // predefined load for hash table
#define EMPTY '/0'  // defined value for empty vector element

int hasher(int value, int hash);
vector<int> buildHashTable(int &hash);
int getNextPrime(int input);
void getCommands(vector<int> &hashTable, int &hash);
bool ratioIsOK(vector<int> &hashTable);
int getNextPrime(int input);
void rehash(vector<int> &hashTable, int &hash);
void insert(vector<int> &hashTable, int value, int &hash);
void displayStatus(vector<int> &hashtable, int index);
void tableSize(vector<int> &hashTable);
void search(vector<int> hashTable, int value, int hash);

void getCommands(vector<int> &hashTable, int &hash) {
    string command;
    cin >> command;
    if (command == "insert") {
        int value;
        cin >> value;
        insert(hashTable, value, hash);
    } else if (command == "displayStatus") {
        int index;
        cin >> index;
        displayStatus(hashTable, index);
    } else if (command == "search") {
        int value;
        cin >> value;
        search(hashTable, value, hash);
    } else if (command == "tableSize") {
        tableSize(hashTable);
    }
}

void print(vector<int> v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int hash = 0;
    vector<int> hashTable = buildHashTable(hash);

    int commands;
    cin >> commands;
    for (int x = 0; x < commands; x++)
        getCommands(hashTable, hash);

    return 0;
}

/**
 * The hash function
 * @param int value to be hashed.
 * @param int hash the hash value used to hash.
 */
int hasher(int value, int hash) {
    return value % hash;
}

/**
 * Takes user input and builds the initial hash table.
 * @returns vector<int> hash table.
 */
vector<int> buildHashTable(int &hash) {
    int hashTableSize;
    cin >> hashTableSize;
    vector<int> hashTable(hashTableSize, EMPTY);
    hash = hashTableSize;  // will always be prime //getNextPrime(hashTableSize);

    return hashTable;
}

/**
 * Checks if the ratio of used to empty spaces is good i.e., less than 0.5.
 * @param vector<int> &hashtable to be evaluated.
 * @returns boolean
 */
bool ratioIsOK(vector<int> &hashTable) {
    int counter = 1;  // start at 1 to see what the ratio would be like post insertion.
    for (auto x : hashTable) {
        if (x != EMPTY) {
            counter++;
        }
    }
    double ratio = (double)counter / (double)hashTable.size();
    if (ratio > LOAD) {
        return false;
    }
    return true;
}

/**
 * Generates the next prime number for the input value. Using the 
 * Sieve of Eratosthenes method.
 * @param int input the input value
 * @returns the next prime number.
 */
int getNextPrime(int input) {
    int primes = input + 11;  // next 11 for safety
    vector<bool> prime(primes, true);
    int p = 2;
    while (p * p <= primes) {
        if (prime[p] == true) {
            for (int x = p * p; x < primes; x += p) {
                prime[x] = false;
            }
        }
        p++;
    }
    for (int x = input + 1; x < primes; x++) {
        if (prime[x]) {
            return x;
        }
    }

    return 0;
}

/**
 * Peforms the rehashing of a table into a larger table (2n).
 * @param vector<int> &hashtable to be hased.
 * @param int &hash key to be updated
 */
void rehash(vector<int> &hashTable, int &hash) {
    hash = getNextPrime(hashTable.size() * 2);
    vector<int> newHashTable(hash, EMPTY);  // new hash value for new table size.

    int key;
    for (auto value : hashTable) {
        if (value != EMPTY) {
            key = hasher(value, hash);
            newHashTable[key] = value;
        }
    }
    hashTable = newHashTable;
}

/** Performs the insert operation according to the linear probe model.
 * @param vector<int> &hashtable that will be used.
 * @param int value the value that will be added
 * @param &hash the hash value used.
 */
void insert(vector<int> &hashTable, int value, int &hash) {
    int key = hasher(value, hash);
    if (ratioIsOK(hashTable)) {
        // increments the key counter if it already in use.
        while (hashTable[key] != EMPTY) {
            key++;
            // resets key to 0 to wrap around.
            if (key == hashTable.size()) {
                key = 0;
            }
        }
        hashTable[key] = value;
    } else {
        rehash(hashTable, hash);
        insert(hashTable, value, hash);  // recusion ;)
    }
}

/**
 * Displays the status of the index queried.
 * @param vector<int> &hashtable the table to be queried.
 * @param int index to be queried.
 */
void displayStatus(vector<int> &hashtable, int index) {
    if (hashtable[index] != EMPTY) {
        cout << hashtable[index] << endl;
    } else {
        cout << "Empty" << endl;
    }
}

/**
 * Displays the table size of a hashtable.
 * @param vector<int> &hashtable.
 */
void tableSize(vector<int> &hashTable) {
    cout << hashTable.size() << endl;
}

/**
 * Peforms the search operations of the hash table, and outputs whether found
 * or not.
 * @param vector<int> hashtable table to be searched
 * @param int value value that is being requested.
 * @param int hash to perform hash lookup
 */
void search(vector<int> hashTable, int value, int hash) {
    int hashIndex = hasher(value, hash);
    int notFound = 0;
    bool isFound = true;  // assume value exists

    // will execute if the first value isn't in the requested index.
    while (hashTable[hashIndex] != value) {
        hashIndex++;
        notFound++;
        if (hashIndex == hashTable.size() - 1) {
            hashIndex = 0;
        }
        if (notFound == hashTable.size()) {
            isFound = false;  // if value isn't found after n searches.
            break;
        }
    }

    if (isFound) {
        cout << value << " Found" << endl;
    } else {
        cout << value << " Not found" << endl;
    }
}