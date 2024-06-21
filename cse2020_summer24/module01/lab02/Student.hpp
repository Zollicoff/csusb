/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 02
 * Date: June 04, 2024
 * 
 * This is the Student class definition. The Student class has two private data members: id and name.
*/


#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

using namespace std;

class Student {
public:
    // Default constructor
    Student():id(0), name("") {

    }

    // Creates a student with the specified id and name.
    Student(int idValue, const string& nameValue): id(idValue), name(nameValue) {

    }

    // Returns the student name.
    string getName() const {
        return name;
    }

    // Returns the student id.
    int getId () const {
        return id;
    }

    // Sets the student name.
    void setName(const string& nameValue) {
        name = nameValue;
    }

    // Sets the student id.
    void setId(int idValue) {
        id = idValue;
    }
 
    // Prints the student id and name.
    void printStudent() const {
        cout << id << " " << name << endl;
    }

private:
    // student name
    string name;

    // student id
    int id;
};

#endif