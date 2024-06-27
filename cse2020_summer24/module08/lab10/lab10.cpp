#include "Set.hpp"
#include <iostream>

using namespace std;

// Function to print a set
template <typename C> 
void print(const Set<C> & s) { 
    for (typename Set<C>::iterator itr = s.begin(); itr != s.end(); ++itr) 
        cout << *itr << ", "; 
    cout << endl; 
}

// Set union A + B
template <typename C> 
Set<C> operator+(const Set<C> & s1, const Set<C> & s2) { 
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) 
        result.insert(*itr); 
        
    for (typename Set<C>::iterator itr = s2.begin(); itr != s2.end(); ++itr) 
        result.insert(*itr); 
    
    return result; 
}

// Set subtraction A - B
template <typename C> 
Set<C> operator-(const Set<C> & s1, const Set<C> & s2) { 
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) 
        if (!s2.contains(*itr)) // Only insert if s2 does not contain the element
            result.insert(*itr); 
    return result; 
}

// Set intersection A * B
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
    int x = 0;

    cout << "Create setA (enter 0 to stop): " << endl;
    while (cin >> x && x != 0) {
        setA.insert(x);
    }
    cout << "The setA is: ";
    print(setA);

    Set<int> setB;

    cout << "Create setB (enter 0 to stop): " << endl;
    while (cin >> x && x != 0) {
        setB.insert(x);
    }
    cout << "The setB is: ";
    print(setB);

    Set<int> theunion = setA + setB;
    cout << "Union of setA and setB: ";
    print(theunion);

    Set<int> thediff = setA - setB;
    cout << "Difference of setA and setB: ";
    print(thediff);

    Set<int> theinter = setA * setB;
    cout << "Intersection of setA and setB: ";
    print(theinter);

    return 0;
}
