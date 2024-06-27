// lab10.cpp
#include "Set.hpp"
#include <iostream>
using namespace std;

template <typename C>
void print(const Set<C> & s)
{
    for (typename Set<C>::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

template <typename C>
Set<C> operator+(const Set<C> & s1, const Set<C> & s2)
{
    Set<C> result = s1;
    for (typename Set<C>::iterator it = s2.begin(); it != s2.end(); ++it) {
        result.insert(*it);
    }
    return result;
}

// Overload the - operator to return the difference of two sets
template <typename C>
Set<C> operator-(const Set<C> & s1, const Set<C> & s2)
{
    Set<C> result;
    for (typename Set<C>::iterator it = s1.begin(); it != s1.end(); ++it) {
        if (!s2.contains(*it)) {
            result.insert(*it);
        }
    }
    return result;
}

// Overload the * operator to return the intersection of two sets
template <typename C>
Set<C> operator*(const Set<C> & s1, const Set<C> & s2)
{
    Set<C> result;
    for (typename Set<C>::iterator it = s1.begin(); it != s1.end(); ++it) {
        if (s2.contains(*it)) {
            result.insert(*it);
        }
    }
    return result;
}

int main()
{
    int x = 0;
    Set<int> setA;
	
    cout << "Create setA (enter 0 to stop): " << endl;
    while (true) {
        cin >> x;
        if (x == 0) break;
        setA.insert(x);
    }
    cout << "setA: ";
    print(setA);
    cout << endl;
  
    Set<int> setB;

    cout << "Create setB (enter 0 to stop): " << endl;
    while (true) {
        cin >> x;
        if (x == 0) break;
        setB.insert(x);
    }
    cout << "setB: ";
    print(setB);
    cout << endl;
 
    Set<int> theunion = setA + setB;
    cout << "Union: ";
    print(theunion);
    cout << endl;

    Set<int> thediff = setA - setB;
    cout << "Difference (A - B): ";
    print(thediff);
    cout << endl;

    Set<int> theinter = setA * setB;
    cout << "Intersection: ";
    print(theinter);
    cout << endl;
  
    return 0;
}

