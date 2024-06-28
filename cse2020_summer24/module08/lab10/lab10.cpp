/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 10
 * Date: June 28, 2024
 * 
 * This program creates sets of integers and performs union, difference, and intersection operations.
*/

// lab10.cpp
#include "Set.hpp"
using namespace std;

// Function to print the values of a set
template <typename C>
void print(const Set<C> & s) {
    for (typename Set<C> :: iterator itr = s.begin(); itr != s.end(); ++itr)
    cout << *itr << ",";
}

// Function for union of two sets
template <typename C>
Set<C> operator+(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result;

    for(typename Set<C> :: iterator itr = s1.begin(); itr != s1.end(); ++itr)
        result.insert(*itr);

    for(typename Set<C> :: iterator itr = s2.begin(); itr != s2.end(); ++itr)
        result.insert(*itr);

    return result;
}

// Function for difference of two sets
template <typename C>
Set<C> operator-(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result;

    for(typename Set<C> :: iterator itr = s1.begin(); itr != s1.end(); ++itr)
        result.insert(*itr);

    for(typename Set<C> :: iterator itr = s2.begin(); itr != s2.end(); ++itr)
        result.remove(*itr);

    return result;
}

// Function for intersection of two sets
template <typename C>
Set<C> operator*(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result;

    for (typename Set <C> :: iterator itr = s1.begin(); itr != s1.end(); ++itr)
        if (s2.contains(*itr))
        result.insert(*itr);

    return result;
}

int main() {
    int x;
    
    // Set A is created and values are inserted and printed
    Set<int> setA;
    cout << "insert the values to setA (stop when entering 0):" << endl;
    while (true) {
        cin >> x;
        if (x == 0) break;
        setA.insert(x);
    }
    cout << "print the values:" << endl;
    print(setA);
    cout << endl << endl;

    // Set B is created and values are inserted and printed
    Set<int> setB;
    cout << "insert the values to SetB (stop when entering 0):" << endl;
    while (true) {
        cin >> x;
        if (x == 0) break;
        setB.insert(x);
    }
    cout << "print the values:" << endl;
    print(setB);
    cout << endl << endl;

    // Union of the two sets are calculated and printed
    Set<int> theunion = setA + setB;
    cout << "The union of two sets: ";
    print(theunion);
    cout << endl;

    // Difference of the two sets are calculated and printed
    Set<int> thediff = setA - setB;
    cout << "The difference of two sets: ";
    print(thediff);
    cout << endl;

    // Intersection of the two sets are calculated and printed
    Set<int> theinter = setA * setB;
    cout << "The intersection of two sets: ";
    print(theinter);
    cout << endl;

    return 0;
}
