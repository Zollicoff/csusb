// lab10.cpp
#include "Set.hpp"
#include <iostream>
using namespace std;

// Print the set function
template <typename C> 
void print(const Set<C> & s){ 
    for (typename Set<C>::iterator itr = s.begin(); itr != 
        s.end(); ++itr) 
        cout << *itr << ", "; 
}

// Overload the + operator to return the union of two sets
template <typename C> 
Set<C> operator+(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != 
    s1.end(); ++itr) 
        result.insert(*itr);
    
    for (typename Set<C>::iterator itr = s2.begin(); itr != 
    s2.end(); ++itr) 
        result.insert(*itr); 
    
    return result; 
}

// Overload the - operator to return the difference of two sets
template <typename C> 
Set<C> operator-(const Set<C> & s1, const Set<C> & s2) { 
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != 
    s1.end(); ++itr) 
        if (!s2.contains(*itr))
            result.insert(*itr); 
    return result; 
}

// Overload the * operator to return the intersection of two sets
template <typename C> 
Set<C> operator*(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) 
        if (s2.contains(*itr)) 
            result.insert(*itr); 
    return result; 
}

int main() {
    Set<int> setA;
    Set<int> setB;
    int value;

    // Create setA
    cout << "insert the values to setA (stop when entering 0):" << endl;
    while (true) {
        cin >> value;
        if (value == 0) break;
        setA.insert(value);
    }

    // Print setA
    cout << "print the values:" << endl;
    print(setA);
    cout << endl;

    // Create setB
    cout << "insert the values to SetB (stop when entering 0):" << endl;
    while (true) {
        cin >> value;
        if (value == 0) break;
        setB.insert(value);
    }

    // Print setB
    cout << "print the values:" << endl;
    print(setB);
    cout << endl;

    // Perform and print union
    Set<int> unionSet = setA + setB;
    cout << "The union of two sets: ";
    print(unionSet);
    cout << endl;

    // Perform and print difference
    Set<int> differenceSet = setA - setB;
    cout << "The difference of two sets: ";
    print(differenceSet);
    cout << endl;

    // Perform and print intersection
    Set<int> intersectionSet = setA * setB;
    cout << "The intersection of two sets: ";
    print(intersectionSet);
    cout << endl;

    return 0;
}
