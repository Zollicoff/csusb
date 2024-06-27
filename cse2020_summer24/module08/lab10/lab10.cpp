// lab10.cpp

#include "Set.hpp"

using namespace std;

// Function to print a set
template <typename C> 
void print(const Set<C> & s)
{ 
    for (typename  Set<C>::iterator itr = s.begin(); itr != s.end(); ++itr) 
        cout << *itr << ", "; 
}

// Set union A + B
template <typename C> 
Set<C> operator+(const Set<C> & s1, const Set<C> & s2) 
{ 
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) 
        result.insert(*itr); 
        
    for (typename Set<C>::iterator itr = s2.begin(); itr != s2.end(); ++itr) 
        result.insert(*itr); 
    
    return result; 
}

// Set subtraction A - B
template <typename C> 
Set<C> operator-(const Set<C> & s1, const Set<C> & s2) 
{ 
    Set<C> result; 
    for (typename Set<C>::iterator itr = s1.begin(); itr != s1.end(); ++itr) 
        result.insert(*itr); 
        
    for (typename Set<C>::iterator itr = s2.begin(); itr != s2.end(); ++itr) 
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
	
    cout << "Create setA : " << endl;
    cin >> x;
    // add your code
    while (x != 0)
    {
        setA.insert(x);
        cin >>x;
    }
    cout << "The setA is: ";
    print(setA);
    cout << endl ;
  
    Set<int> setB;

    cout << "create setB: " << endl;
    cin >> x;
    // add your code
    while (x != 0)
    {
        setB.insert(x);
        cin >> x;
    }
    cout << "The setB is:";
    print(setB);
    cout << endl ;
 
    Set<int> theunion = setA + setB;
    cout << "union: " << endl;
    print(theunion);
    cout << endl;

    Set<int> thediff = setA - setB;
    cout << "subtraction: " << endl;
    print(thediff);
    cout << endl;

    Set<int> theinter = setA * setB;
    cout << "intersection" << endl;
    print(theinter);
    cout << endl;
  
    return 0;
}

