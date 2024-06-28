#include <iostream>
#include <string>
#include "BinaryHeap.hpp"

using namespace std;

int main()
{
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