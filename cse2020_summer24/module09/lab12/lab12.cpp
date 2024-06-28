/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 12
 * Date: June 28, 2024
 * 
 * This program uses a binary heap to simulate a print queue.
 * The user inputs the priority of print jobs, and the program inserts 
 * them into the queue. The user then inputs the number of jobs the
 * printer will run, and the program deletes the minimum priority job
 * that many times. Finally, the program prints the remaining jobs in
 * the queue.
*/

// lab12.cpp
#include <iostream>
#include <string>
#include "BinaryHeap.hpp"

using namespace std;

int main() {
    BinaryHeap<int> printQueue;
    int x;

    // Input priority values and insert them into the queue
    while (true) {
        cout << "The priority of print job?: ";
        cin >> x;
        
        if (x == -1) break;
        
        printQueue.insert(x);
    }

    // Print the initial heap
    cout << "\nThe priority values of print jobs: ";
    printQueue.printHeap();
    cout << endl;

    // Get the number of jobs to run
    int n;
    cout << "\nThe number of jobs the printer will run?: ";
    cin >> n;

    // Delete the minimum n times
    for (int i = 0; i < n; i++) {
        if (!printQueue.isEmpty()) {
            printQueue.deleteMin();
        }
    }

    // Print the remaining jobs
    cout << "\nThe priority values of remaining print jobs: ";
    printQueue.printHeap();
    cout << endl;

    return 0;
}