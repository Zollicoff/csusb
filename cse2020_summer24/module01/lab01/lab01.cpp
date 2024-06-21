/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 01
 * Date: June 04, 2024

 * This program reads a list of integers from a file named "search.txt" into an array.
 * It then prompts the user to enter a key to search for in the array and error checks for proper input.
 * The program uses a linear search algorithm to find the first occurrence of the key in the array.
 * If the key is found, the program prints the index of the key in the array.
 * If the key is not found, the program prints a message indicating this.
 */

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

// The maximum capacity of the array
const int CAPACITY = 100;

// Function prototype for the linear search function
int linearSearch(int a[], int size, int key);

int main() {

    // Declare and initialize the array and other variables
    int list[CAPACITY] = {};
    int number = 0, size = 0, i = 0, k = 0, index = 0;
   
    // Open the input file and read the numbers into the array
    ifstream input("search.txt");
    while (input >> number) {
        list[i] = number;
        i++;
    }
    input.close();
   
    // The actual size of the array is the number of numbers read from the file
    size = i;

    // Print the array
    cout << "The array: ";
    for (int j = 0; j < size; j++) {
        cout << list[j] << " ";
    }
    cout << endl;

    // Prompt the user to enter a key to search for
    cout << "\nEnter the key: ";
    while(!(cin >> k)) {
        cout << "\nInvalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
   
    // Search for the key in the array
    index = linearSearch(list, size, k);

    // Print the result of the search
    if (index != -1) {
        cout << "\nThe key " << k << " is at the index " << index << "." << endl;
    } else {
        cout << "\nThe key is not in the array." << endl;
    }
   
    return 0;
}

// The linear search function
int linearSearch(int a[], int size, int key) {
    
    // Go through each element in the array
    for (int i = 0; i < size; i++) {
        // If the current element is the key, return its index
        if (a[i] == key) {
            return i;
        }
    }
    // If the key is not found in the array, return -1
    return -1;
}
