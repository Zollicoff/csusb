/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 06
 * Date: June 14, 2024
 * 
 * Information:
 * This program creates sequences of parentheses and checks if they are balanced.
 * The program prompts the user to enter a sequence of parentheses and checks if they are balanced.
 * The program uses a stack to keep track of the parentheses and checks if they are balanced.
 * The program then displays whether the parentheses are balanced or unbalanced.
*/

// lab06.cpp
#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

// Main function to check if the parentheses are balanced
int main() {
    Stack<char> sc;
    char c;
    bool balanced = true;
    
    // Prompt the user to enter the sequence of parentheses
    cout << "Enter the sequence: ";
    while (cin >> c && c != 'x') {
        if (c == '(') {
            sc.push(c); // Push opening parentheses onto the stack
        } else if (c == ')') {
            if (!sc.empty()) { // Check if the stack is not empty
                sc.pop(); // Pop the corresponding opening parentheses
            } else {
                balanced = false;
                break;
            }
        }
    }
    
    if (balanced && sc.empty()) { // Check if the stack is empty
        cout << "The parentheses are balanced." << endl;
    } else { // If the stack is not empty or the parentheses are not balanced
        cout << "The parentheses are unbalanced." << endl;
    }
    
    return 0;
}