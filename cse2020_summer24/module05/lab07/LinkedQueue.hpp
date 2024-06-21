/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 07
 * Date: June 14, 2024
 * 
 * Information:
 * This class creates a singly linked queue of integers, strings, and employees.
*/

// LinkedQueue.cpp
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename T>
class Queue {
public:
    // Constructor
    Queue() {
	    front = nullptr;
	    back = nullptr;
    }
    
    //Desctructor
    ~Queue() {
	    clear();
    }  

    // Makes the queue to the empty state.  
    void clear() {
	    while (!empty()) {
		    dequeue();
	    }
    }
    
    // Checks if the queue is empty.  
    bool empty() const {
	    return (front == nullptr && back == nullptr);
    }
    
    // Inserts item at the end of the queue.
    void enqueue(const T& item) {
	    NodeType* new_node = new NodeType(item);
    
	    if (empty()) {
    	  	// add the first element 
	  	    front = new_node;
	  	    back = new_node;
	    } else {
    	  	back->next = new_node;
	  	    back = new_node;
	    }
    }

    // Removes the element at the start of the queue.
    void dequeue() {
	    if (!empty()) {
    	  	NodeType* ptr = front;
	  	    front = front->next;
	  	    delete ptr;	
	  	    // dequeue the last element
	  	    if (front == nullptr)
    	  		back = nullptr;
	    }
    }
	
	// returns the front element
    const T& front_element() const {
	    return front->data; 
    }
  
    // Prints the elements of the queue.
    void print() const {
	    NodeType* ptr = front;
	    while (ptr != nullptr) {
		    cout << ptr->data << ", ";
		    ptr = ptr->next;
	    }
	    cout << endl;
    }  
  
private:
    struct NodeType {
        T data;
        NodeType* next;
	  
        NodeType(const T & d = T()): data(d), next(nullptr) { }	  
    };
  
    NodeType* front;
    NodeType* back;
};

#endif