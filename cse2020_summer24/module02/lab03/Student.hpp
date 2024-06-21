/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 03
 * Date: June 07, 2024
 * 
 * This is the implementation file for the Student class and NodeType structure.
 * The Student class represents a student with an id and name.
 * The NodeType structure is a template structure for linked list nodes.
 * The Student class and NodeType structure are used in the main program to store
 * student information in a linked list.
 * The main program is in lab03.cpp.
*/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

using namespace std;

// Definition of the Student class
class Student {
public:
    // Default constructor initializes student with default values
    Student(): id(0), name("") {
        
    }

    // Constructor that initializes a student with specified id and name
    Student(int idValue, const string& nameValue): id(idValue), name(nameValue) {

    }

    // Returns the student's name
    string getName() const {
        return name;
    }

    // Returns the student's id
    int getId() const {
        return id;
    }

    // Sets the student's name
    void setName(const string& nameValue) {
        name = nameValue;
    }

    // Sets the student's id
    void setId(int idValue) {
        id = idValue;
    }

    // Prints the student's id and name to the console
    void printStudent() const {
        cout << id << name << endl;
    }

private:
    // Private member variables to store the student's name and id
    string name;
    int id;
};

// Template structure for the NodeType, to be used in linked lists
template <typename T>
struct NodeType {
    T data;           // Data element of type T
    NodeType* next;   // Pointer to the next node in the list

    // Default constructor initializes the node with default values for T and sets next to nullptr
    NodeType(): data(), next(nullptr) {

    }

    // Constructor initializes node with a specific data item and sets next to nullptr
    NodeType(const T& s): data(s), next(nullptr) {
        
    }
};

#endif
