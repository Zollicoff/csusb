/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 07
 * Date: June 14, 2024
 * 
 * Information:
 * This class creates a circular queue of integers, strings, and employees.
*/


// CircularQueue.cpp
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

template <typename T>
class Queue {
public:
    // Constructor
    Queue(int capacity = CAPACITY) {
  	    this->capacity = capacity;
  	    items = new T[capacity];
  	    front = 0;
  	    back = 0;
    }
  
    //Desctructor
    ~Queue() {
      	delete [] items;
    }  

    // Makes the queue to the empty state.  
    void clear() {
      	front = 0;
      	back = 0;
    }
  
    // Checks if the queue is empty.  
    bool empty() const {
      	return (front == back);
    }

    // Checks if the queue is full.  
    bool full() const {
      	return (((back + 1) % capacity) == front);
    }
  
      // Inserts item at the end of the queue.
    void enqueue(const T& item) {
  	    if(!full()) {
  	  	    back = (back + 1) % capacity;
      	  	items[back] = item;	
    	}   
    }

    // Removes the element at the start of the queue.
    void dequeue() {
  	    if(!empty()) {
      	  	front = (front + 1) % capacity;
  	    }
    }
	
	// returns the front element
    const T& front_element() const {
      	return items[(front + 1) % capacity];
    }
    
    // Prints the elements of the queue.
    void print() const {
      	int i = (front + 1) % capacity;
      	while (i <= back) {
  	  	    cout << items[i] << ", ";
  	  	    i = (i + 1) % capacity;
  	    }
  	    cout << endl;
    }  

    const static int CAPACITY = 50;
    
private: 
  	T* items;
  	int capacity;
  	int front;
  	int back;
};

#endif
