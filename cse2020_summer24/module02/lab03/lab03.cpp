/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 03
 * Date: June 07, 2024
 * 
 * This program reads student id and name from the user and stores them in a linked list
 * of Student objects. The program then prints the student id and name in the linked list.
 * The program uses the Student class defined in Student.cpp.
 * The program uses the NodeType structure defined in Student.cpp.
*/

#include "Student.hpp"
#include <iostream>

using namespace std;

// Main function that demonstrates linked list operations with the Student class
int main() {
    int id;
    string name;
    NodeType<Student>* head = nullptr; // Pointer to the first node of the linked list
    NodeType<Student>* cur = nullptr; // Pointer to the current node in the linked list

    // Prompt user to enter student details
    do {
        cout << "Enter the student id (int) and name (string): ";
        cin >> id;
        if (id == 0) break;  // Sentinel value to stop input
        getline(cin, name);  // Get the rest of the line after the integer id

        // Create a new Student object with the given id and name
        Student newStudent(id, name);
        // Create a new node for the linked list containing the new student
        NodeType<Student>* newNode = new NodeType<Student>(newStudent);

        // Inserting the new node at the beginning of the linked list
        newNode->next = head;
        head = newNode;
    } while (true);

    // Display all students in the linked list
    cout << "\nThe students are:\n";
    cur = head;
    while  (cur != nullptr) {
        cur->data.printStudent();
        cur = cur->next;
    }

    // Cleanup: delete all nodes to prevent memory leaks
    while (head != nullptr) {
        cur = head;
        head = head->next;
        delete cur;
    }

    return 0;
}
