// lab10.cpp
#include "Set.hpp"
#include <iostream>
using namespace std;

// Add 4 functions
template <typename C>
void print(const Set<C> & s) {
    for (typename Set<C>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << ",";
    }
}

// Union of two sets
template <typename C>
Set<C> operator+(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result;
    
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) {
        result.insert(*itr);
    }
    
    for (typename Set<C>::iterator itr = s2.begin(); itr != s2.end(); ++itr) {
        result.insert(*itr);
    }
    
    return result;
}

// Difference of two sets
template <typename C>
Set<C> operator-(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result;
    
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) {
        if (!s2.contains(*itr)) {
            result.insert(*itr);
        }
    }
    
    return result;
}

// Intersection of two sets
template <typename C>
Set<C> operator*(const Set<C> & s1, const Set<C> & s2) {
    Set<C> result;
    
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) {
        if (s2.contains(*itr)) {
            result.insert(*itr);
        }
    }
    
    return result;
}

int main() {
    int x;
    
    Set<int> setA;
    cout << "insert the values to setA (stop when entering 0):" << endl;
    while (true) {
        cin >> x;
        if (x == 0) break;
        setA.insert(x);
    }
    
    cout << "print the values:" << endl;
    print(setA);
    cout << endl;
 
    Set<int> setB;
    cout << "insert the values to SetB (stop when entering 0):" << endl;
    while (true) {
        cin >> x;
        if (x == 0) break;
        setB.insert(x);
    }

    cout << "print the values:" << endl;
    print(setB);
    cout << endl;
 
    Set<int> theunion = setA + setB;
    cout << "The union of two sets: ";
    print(theunion);
    cout << endl;

    Set<int> thediff = setA - setB;
    cout << "The difference of two sets: ";
    print(thediff);
    cout << endl;

    Set<int> theinter = setA * setB;
    cout << "The intersection of two sets: ";
    print(theinter);
    cout << endl;
 
    return 0;
}
