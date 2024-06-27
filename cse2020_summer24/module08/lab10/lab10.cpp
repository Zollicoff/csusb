// lab10.cpp
#include "Set.hpp"
using namespace std;

// Print the set function
template <typename C> 
void print(const Set<C> & s){ 
    for (typename  Set<C>::iterator itr = s.begin(); itr != 
        s.end(); ++itr) 
        cout << *itr << ","; 
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
        result.insert(*itr);
    
    for (typename Set<C>::iterator itr = s2.begin(); itr != 
    s2.end(); ++itr) 
        result.remove(*itr); 
    
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
    int x = 0;
    Set<int> setA;
	
    // Create and print setA
    cout << "Create setA: " << endl;
    while (cin >> x && x != -1) {
        setA.insert(x);
    }
    print(setA);
    cout << endl ;
  
    Set<int> setB;

    // Create and print setB
    cout << "create setB: " << endl;
    while (cin >> x && x != -1) {
        setB.insert(x);
    }
    print(setB);
    cout << endl ;
 
    // Perform union, subtraction, and intersection
    Set<int> theunion = setA + setB;
    cout << "union: " << endl;
    print(theunion);
    cout << endl;

    // Perform subtraction, and intersection
    Set<int> thediff = setA - setB;
    cout << "subtraction: " << endl;
    print(thediff);
    cout << endl;

    // Perform intersection
    Set<int> theinter = setA * setB;
    cout << "intersection" << endl;
    print(theinter);
    cout << endl;
  
    return 0;
}

