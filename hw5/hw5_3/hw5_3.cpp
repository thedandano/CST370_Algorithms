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

vector<int> buildHashTable(int &hash);
int getNextPrime(int input);
void getCommands();
bool ratioIsOK(vector<int> &hashTable);
int getNextPrime(int input);
void rehash(vector<int> &hashTable, int &hash);


void insert(vector<int> &hashTable, int value, int &hash)
{
    // int hash = 7;
    int key = value % hash;
    if (ratioIsOK(hashTable))
    {
        hashTable[key] = value;
    }
    else
    {
        rehash(hashTable, hash);
        insert(hashTable, value, hash); // recusion ;)
    }
}

void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int hash = 0;
    vector<int> hashTable = buildHashTable(hash);
    insert(hashTable, 9, hash);
    insert(hashTable, 7, hash);
    insert(hashTable, 8, hash);
    insert(hashTable, 11, hash);
    insert(hashTable, 13, hash);
    insert(hashTable, 15, hash);

    print(hashTable);

    return 0;
}

/**
 * Takes user input and builds the initial hash table.
 * @returns vector<int> hash table.
 */
vector<int> buildHashTable(int &hash)
{
    int hashTableSize;
    cin >> hashTableSize;
    vector<int> hashTable(hashTableSize, '/0');
    hash = getNextPrime(hashTableSize);

    return hashTable;
}

/**
 * Checks if the ratio of used to empty spaces is good i.e., less than 0.5.
 * @param vector<int> &hashtable to be evaluated.
 * @returns boolean
 */
bool ratioIsOK(vector<int> &hashTable)
{
    int counter = 1; // start at 1 to see what the ratio would be like post insertion.
    for (auto x : hashTable)
    {
        if (x != '/0')
        {
            counter++;
        }
    }
    double ratio = (double)counter / (double)hashTable.size();
    if (ratio > 0.5)
    {
        return false;
    }
    return true;
}

/**
 * Generates the next prime number for the input value. Using the Sieve of Eratosthenes
 * method.
 * @param int input the input value
 * @returns the next prime number.
 */
int getNextPrime(int input)
{
    int primes = input + 11; // next 10
    vector<bool> prime(primes, true);
    int p = 2;
    while (p * p <= input)
    {

        if (prime[p] == true)
        {
            for (int x = p * p; x < primes; x += p)
            {
                prime[x] = false;
            }
        }
        p++;
    }
    for (int x = input; x < primes; x++)
    {
        if (prime[x])
        {
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
void rehash(vector<int> &hashTable, int &hash)
{
    vector<int> newHashTable(hashTable.size() * 2, '/0');
    hash = getNextPrime(newHashTable.size());

    int key;
    for (auto value : hashTable)
    {
        if (value != '/0')
        {
            key = value % hash;
            newHashTable[key] = value;
        }
    }
    hashTable = newHashTable;
}