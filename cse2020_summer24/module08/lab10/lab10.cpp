// lab10.cpp
#include "Set.hpp"
using namespace std;

// Function to print a set
template <typename C> 
void print(const Set<C> & s){ 
    for (typename  Set<C>::iterator itr = s.begin(); itr != 
        s.end(); ++itr) 
        cout << *itr << ","; 
}

// Set union A + B
template <typename C> 
Set<C> operator+(const Set<C> & s1, const Set<C> & s2) 
{
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != 
    s1.end(); ++itr) 
        result.insert(*itr);
        
    for (typename Set<C>::iterator itr = s2.begin(); itr != 
    s2.end(); ++itr) 
        result.insert(*itr); 
    return result; 
}

// Set subtraction A - B
template <typename C> 
Set<C> operator-(const Set<C> & s1, const Set<C> & s2) 
{ 
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != 
    s1.end(); ++itr) 
        result.insert(*itr);
    
    for (typename Set<C>::iterator itr = s2.begin(); itr != 
    s2.end(); ++itr) 
        result.remove(*itr); 
    return result; 
} 

// Set intersection A * B
template <typename C> 
Set<C> operator*(const Set<C> & s1, const Set<C> & s2) 
{
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) 
        if (s2.contains(*itr)) 
            result.insert(*itr); 
    return result; 
}


int main()
{
    int x = 0;
    Set<int> setA;
    
    cout << "Insert the values to setA (stop when entering 0):" << endl;
    while(cin >> x && x != 0) { // Change sentinel value to 0
        setA.insert(x);
    }

    cout << "Print the values:" << endl;
    print(setA);
    cout << endl ;
  
    Set<int> setB;

    cout << "Insert the values to setB (stop when entering 0):" << endl;
    while(cin >> x && x != 0) { // Change sentinel value to 0
        setB.insert(x);
    }

    cout << "Print the values:" << endl;
    print(setB);
    cout << endl ;
 
    Set<int> theunion = setA + setB;
    cout << "The union of two sets: " << endl;
    print(theunion);
    cout << endl;

    Set<int> thediff = setA - setB;
    cout << "The difference of two sets: " << endl;
    print(thediff);
    cout << endl;

    Set<int> theinter = setA * setB;
    cout << "The intersection of two sets:" << endl;
    print(theinter);
    cout << endl;
  
    return 0;
}
