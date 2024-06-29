/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 13
 * Date: July 1, 2024
 * 
 * This program uses the merge sort algorithm to sort a list of numbers.
 * The numbers are read from a file, sorted, and then printed to the console.
 * The merge sort algorithm is implemented using templates.
 * The program uses the MergeSort.hpp header file to define the merge sort functions.
*/

// lab13.cpp
#include <fstream>
#include <iostream>
#include "MergeSort.hpp"

using namespace std;

int main() {
    vector<int> v;
    
    // Read values from sort.txt
    ifstream input("sort.txt");
    int number;
    while (input >> number) {
        v.push_back(number);
    }
    input.close();

    // Call merge sort function
    mergeSort(v);

    // Print the sorted items
    cout << "The merge sort: ";
    for (const auto& num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
