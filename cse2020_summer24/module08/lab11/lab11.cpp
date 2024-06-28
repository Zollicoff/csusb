/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 11
 * Date: June 28, 2024
 *
 * This program demonstrates the use of a map data structure.
 * First it takes in a list of student IDs and names and stores them in a map.
 * Then it prints the map.
 * Then it asks for a student ID and prints the corresponding name.
 * Then it asks for a student ID and a new name and changes the name in the map.
 * Then it asks for a student ID and removes that student from the map.
 * Then it prints the map again.
*/

// lab11.cpp
#include <iostream>
#include <string>   
#include "Map.hpp"

using namespace std;

int main()
{
    Map<int,string> studentDB;
    int id;
    string name;
    
    cout << "using index operator to insert new pairs:" << endl;
    
    // Input student IDs and names
    while (true) {
        cout << "Student ID? ";
        cin >> id;
        
        if (id == 0) break;
        
        cout << "Student Name? ";
        cin >> name;
        
        studentDB[id] = name;
        
        cout << endl;
    }
    
    // Print the student database
    cout << "\nContent of student database:" << endl;
    studentDB.printMap();
    cout << endl;
    
    // Find a student by ID
    cout << "Who you want to know? ";
    cin >> id;
    cout << "The corresponding name is: " << studentDB[id] << endl << endl;
    
    // Change a student's name
    cout << "Change which one? ";
    cin >> id;
    cout << "... to what name? ";
    cin >> name;
    studentDB[id] = name;
    cout << endl;
    
    studentDB.printMap();
    cout << endl;
    
    // Remove a student
    cout << "Remove which one? ";
    cin >> id;
    studentDB.remove(id);
    cout << endl;
    
    studentDB.printMap();
    
    return 0;
}
