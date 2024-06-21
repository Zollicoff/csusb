/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 06
 * Date: June 14, 2024
 * 
 * Information:
 * This class implements a stack using a template class.
 * The stack has the following operations:
 * - empty: Checks if the stack is empty.
 * - clear: Makes the stack empty.
 * - push: Inserts an item into the stack.
 * - top: Returns the top element of the stack.
 * - pop: Removes the top element from the stack. 
*/

// Stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {
public:
    Stack() {
        topOfStack = -1; // Initialize the stack to empty
        items = new T[CAPACITY]; // Allocate memory for the stack
    }
  
    // Destructor
    ~Stack() {
        delete[] items; // Deallocate memory for the stack
    }
  
    // Checks if the stack is empty.  
    bool empty() const {
        return topOfStack == -1; // Return true if the stack is empty
    }
  
    // Makes the stack to the empty state.  
    void clear() {
        topOfStack = -1; // Set the top of the stack to -1
    }
  
    // Insert item in the stack.
    void push(const T& item) {
        if (topOfStack < CAPACITY - 1) { // Check if the stack is not full
            items[++topOfStack] = item; // Insert the item into the stack
        }
    }

    // Return the top element.
    const T& top() const {
        if (!empty()) { // Check if the stack is not empty
            return items[topOfStack]; // Return the top element
        }
        throw std::underflow_error("Stack is empty"); // Throw an exception if the stack is empty
    }
  
    // Removes the top element.
    void pop() {
        if (!empty()) { // Check if the stack is not empty
            --topOfStack; // Remove the top element
        }
    }
  
    static const int CAPACITY = 50; // Maximum capacity of the stack

private:
    int topOfStack;  // -1 for empty stack
    T* items;
};

#endif