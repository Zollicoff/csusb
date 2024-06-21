/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 07
 * Date: June 14, 2024
 * 
 * Information:
 * This program creates a queue of integers, strings, and employees.
 * The program prompts the user to enter positive integers, strings, and employee information.
*/

// Lab07.cpp - TestQueue
#include <string>
#include "Employee.hpp"
#include "CircularQueue.hpp" // Application of circular queue
#include "LinkedQueue.hpp" // Application of singly linked queue
#include "DoublyLinkedQueue.hpp" // Application of doubly linked queue

int main() { 
    // Test singly linked queue
    Queue<int> intQue;

    int x = 0, k = 0;

    cout << "Enqueue positive numbers (enter 0 to stop): ";
    cin >> x;
    while (x != 0) {  
        intQue.enqueue(x);
        cin >> x;        
    }
    cout << "print queue: ";
    intQue.print(); 
    cout << endl;

    cout << "How many numbers to be removed from queue: ";
    cin >> k;
    cout << endl;
    for (int i = 0; i < k; i++) {
        intQue.dequeue();
    }
    cout << "print queue: ";
    intQue.print();
    cout << endl;

    // Test circular queue
    Queue<string> stringQue;

    string s;

    cout << "Enqueue string (enter exit to stop): ";
    cin >> s;
    while (s != "exit") {  
        stringQue.enqueue(s);
        cin >> s;        
    }
    cout << endl;
    cout << "print queue: ";
    stringQue.print(); 
    
    cout << endl;
    cout << "How many strings to be removed from queue: ";
    cin >> k;

    for (int i = 0; i < k; i++) {
        stringQue.dequeue();
    }
    cout << endl << "print queue: ";
    stringQue.print(); 
    cout << endl;

    // Test doubly linked queue
    Queue<Employee> emplQue;

    string name, dept;
    int id = 0;

    cout << "Enqueue employee id, name, dept(enter id 0 to stop): ";
    cin >> id >> name >> dept;
    while (id != 0) {  
        Employee e(id, name, dept);
        emplQue.enqueue(e);
        cout << "Enqueue employee id, name, dept: ";
        cin >> id >> name >> dept;        
    }
    cout << endl<< "print queue: ";
    emplQue.print();
    cout << endl;
    
    cout << "How many employees to be removed from queue: ";
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        emplQue.dequeue();
    }
    cout << endl << "print queue: ";
    emplQue.print(); 
      
    return 0;
}
