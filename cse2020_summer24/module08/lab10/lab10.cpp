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
	
    // Insert the values to setA
    cout << "insert the values to setA (stop when entering 0):" << endl;
    while (cin >> x && x != 0) {
        setA.insert(x);
    }
    
    // Print the values
    cout << "print the values:" << endl;
    print(setA);
    cout << endl;
  
    Set<int> setB;

    // Insert the values to setB
    cout << "insert the values to SetB (stop when entering 0):" << endl;
    while (cin >> x && x != 0) {
        setB.insert(x);
    }
    
    // Print the values
    cout << "print the values:" << endl;
    print(setB);
    cout << endl;
 
    // Print the minimum value of setA
    Set<int> theunion = setA + setB;
    cout << "The union of two sets: ";
    print(theunion);
    cout << endl;

    // Print the maximum value of setA
    Set<int> thediff = setA - setB;
    cout << "The difference of two sets: ";
    print(thediff);
    cout << endl;

    // Print the maximum value of setA
    Set<int> theinter = setA * setB;
    cout << "The intersection of two sets: ";
    print(theinter);
    cout << endl;
  
    return 0;
}

