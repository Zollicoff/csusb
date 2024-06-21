/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 02
 * Date: June 04, 2024
 * 
 * This program reads student id and name from the user and stores them in a dynamic array 
 * of Student objects. The program then prints the student id and name in the dynamic array.
 * The program uses the Student class defined in Student.cpp. 
*/

#include "Student.hpp"
#include <iostream>
#include <vector>

// I don't feel like typing std a bunch of times
using namespace std;

// Main function
int main() {

    // Declare variables
    int capacity = 0, size = 0, id = 0;
    string name;

    cout << "Enter the capacity of dynamic array (int): ";
    cin >> capacity;    
	cout << endl;

    // Declare a dynamic array of Student objects
    Student* groups = new Student[capacity];

	// Read student id and name from the user
    do {
        cout << "Enter the student id (int) and name (string): ";
        cin >> id;
        cin.ignore(); // Ignore the newline character left in the input buffer by cin

        if (id != 0) {
            getline(cin, name); // Get the entire line as the student name

            // Create a new Student object
            Student newStudent(id, name);

            // Add the new Student object to the dynamic array
            groups[size] = newStudent;

            // Increment the size variable
            size++;
        }
    } while (id != 0 && size < capacity);

    // Print out the student id and name in the dynamic array
    cout << "\nThe students are:\n";
    for (int i = 0; i < size; i++) {
        groups[i].printStudent();
    }

    // Deallocate the dynamic array
    delete[] groups;

    return 0;
}
