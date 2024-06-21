/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 05
 * Date: June 14, 2027
 * This class implements a linked list of any type.
 * The class provides methods to add, remove, and find elements in the list.
 * The class also provides an iterator to traverse the list.
*/

// LinkedList.cpp
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename T>
class LinkedList {

private:
    // NodeType structure representing each node in the linked list
    struct NodeType {
        T data;
        NodeType* next;
        NodeType(): data(), next(nullptr) {}
        NodeType(const T& d): data(d), next(nullptr) {}
    };

public:
    // Default constructor
    LinkedList(): size(0), head(new NodeType()) {}

    // Destructor to clear the list and free memory
    ~LinkedList() {
        clear();
        delete head;
    }

    // Returns true if the linked list is empty
    bool empty() const {
        return size == 0;
    }

    // Clears the linked list
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Returns the number of items in the linked list
    int get_size() const {
        return size;
    }

    // Checks if the item is in the linked list
    bool find(const T& item) const {
        NodeType* current = head->next;
        while (current != nullptr) {
            if (current->data == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Inserts an item at the front of the linked list
    void push_front(const T& item) {
        NodeType* newNode = new NodeType(item);
        newNode->next = head->next;
        head->next = newNode;
        ++size;
    }

    // Removes the first item from the linked list
    void pop_front() {
        if (!empty()) {
            NodeType* temp = head->next;
            head->next = head->next->next;
            delete temp;
            --size;
        }
    }

public:
    // Iterator class for the linked list
    class iterator {
    
    public:
        iterator(): current(nullptr) {}
        
        // Dereference operator
        T& operator*() {
            return current->data;
        }
        
        // Pre-increment operator
        iterator& operator++() {
            current = current->next;
            return *this;
        }
        
        // Equality operator
        bool operator==(const iterator& rhs) const {
            return current == rhs.current;
        }

        // Inequality operator
        bool operator!=(const iterator& rhs) const {
            return !(*this == rhs);
        }

    private:
        NodeType* current;
        friend class LinkedList<T>;
    };

    // Returns an iterator to the beginning of the linked list
    iterator begin() {
        iterator itr;
        itr.current = head->next;
        return itr;
    }
    
    // Returns an iterator to the end of the linked list
    iterator end() {
        iterator itr;
        itr.current = nullptr;
        return itr;
    }

private:
    int size;          // The size of the linked list
    NodeType* head;    // Points to the header node
};

#endif
