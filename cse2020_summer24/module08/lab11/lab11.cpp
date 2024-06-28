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
