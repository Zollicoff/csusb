/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 05
 * Date: June 14, 2024
 * This program creates a linked list of integers, strings, and employees.
 * The program prompts the user to enter values for each type and adds them to the linked list.
 * The program then displays the size of the linked list, the elements in the list, and whether a key is present in the list.
 * The program also removes a specified number of elements from the front of the list and displays the updated list.
*/

// lab05.cpp
#include <iostream>
#include <string>
#include "employee.hpp"
#include "linkedlist.hpp"

using namespace std;

// Function to print the elements of the linked list
template <typename C>
void print(LinkedList<C>& l) {
    for (typename LinkedList<C>::iterator itr = l.begin(); itr != l.end(); ++itr) {
        cout << *itr << ", ";
    }
    cout << endl;
}

int main() {
    // Part 1: Integer LinkedList
    LinkedList<int> intll;
    int x = 0;
    cout << "Create a list of integers: \n";
    while (true) {
        cin >> x;
        if (x == 0) break; // Stop input when 0 is entered
        intll.push_front(x);
    }
    
    cout << endl;
    cout << "The size of the linked list is: " << intll.get_size() << endl;
    cout << "The linked list is: " << endl;
    print(intll);
    cout << endl;

    cout << "Enter the key: ";
    int key;
    cin >> key;
    cout << "Is the key in the list? " << intll.find(key) << endl;
    cout << endl;

    cout << "How many values do you want to remove? ";
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        intll.pop_front(); // Remove k values from the front
    }
    cout << endl;
    cout << "The list is: ";
    cout << endl;
    print(intll);
    cout << endl;
    
    // Part 2: String LinkedList
    LinkedList<string> strll;
    string str;
    cout << "Create a list of strings: ";
    cout << endl;
    while (true) {
        cin >> str;
        if (str == "exit") break; // Stop input when "exit" is entered
        strll.push_front(str);
    }
    cout << endl;
    cout << "The size of the linked list is: " << strll.get_size() << endl;
    cout << "The linked list is: ";
    cout << endl;
    print(strll);
    cout << endl;

    cout << "How many values do you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; ++i) {
        strll.pop_front(); // Remove k values from the front
    }
    cout << "The linked list is: ";
    cout << endl;
    print(strll);

    // Part 3: Employee LinkedList
    LinkedList<Employee> empLL;
    Employee emp;
    cout << endl;
    cout << "Create a list of employees:" << endl;
    while (true) {
        cout << "Enqueue employee id, name, dept(enter id 0 to stop): ";
        cin >> emp;
        if (emp.get_id() == 0) break; // Stop input when id 0 is entered
        empLL.push_front(emp);
    }
    cout << endl;
    cout << "The size of the linked list is: " << empLL.get_size() << endl;
    cout << endl;
    cout << "The linked list is: ";
    cout << endl;
    print(empLL);
    cout << endl;

    cout << "How many values do you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; ++i) {
        empLL.pop_front(); // Remove k values from the front
    }
    cout << "The linked list is: ";
    cout << endl;
    print(empLL);

    return 0;
}
