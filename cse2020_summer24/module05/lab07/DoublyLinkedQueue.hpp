/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 07
 * Date: June 14, 2024
 * 
 * Information:
 * This class creates a doubly linked queue of integers, strings, and employees.
*/

// DoublyLinkedQueue.cpp
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename T>
class Queue {
public:
    // Constructor
    Queue() {
	    front = new NodeType;	
	    back = new NodeType;		  
	    front->next = back;
	    back->prev = front;
    }
    
    //Desctructor
    ~Queue() {
	    clear();
	    delete front;  	
	    delete back;  	
    }  

    // Makes the queue to the empty state.  
    void clear() {
        while (!empty()) {
            dequeue();
        }
    }
    
    // Checks if the queue is empty.  
    bool empty() const {
        return (front->next == back);
    }
    
    // Inserts item at the end of the queue.
    void enqueue(const T& item) {
        NodeType* new_node = new NodeType(item);
        new_node->prev = back->prev;
        new_node->next = back;
        back->prev->next = new_node;
        back->prev = new_node;
    }

    // Removes the element at the start of the queue. //TODOOOOO
    void dequeue() {
	    NodeType* ptr = front->next;
	    if (!empty()) {
            front->next = ptr->next;
            ptr->next->prev = front;
            delete ptr;
	    }
    }
    
    // returns the front element
    const T& front_element() const {
        return front->next->data;    
    }
    
    // Prints the elements of the queue.
    void print() const {
	    NodeType* ptr = front->next;
	    while (ptr != back) {
		    cout << ptr->data << ", ";
		    ptr = ptr->next;
	    }
	    cout << endl;
    }  
    
private:
    struct NodeType {
	    T data;
	    NodeType* next;
	    NodeType* prev;
	  
	    NodeType(const T & d = T()): data(d), prev(nullptr), next(nullptr) {}
    };
  
    NodeType* front;
    NodeType* back;
};

#endif
