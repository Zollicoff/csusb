/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 11
 * Date: June 28, 2024
 *
 * This header file defines a pair data structure.
*/

// Pair.cpp
// for class Map, after Mark A. Weiss, Kerstin Voigt

#ifndef PAIR_HPP
#define PAIR_HPP
using namespace std;

template <typename K, typename V>
class Pair {
public:

    Pair() {}

    Pair(K thekey):key(thekey) {}
    
    Pair(K thekey, V theval):key(thekey), value(theval) {}

    K getKey() const {
        return key;  
    }
    
    V& getValue() {
        return value;  
    }  

    void setKey(K k) {
        key = k;
    }

    void setValue(V v) {
        value = v;
    }
    
    bool operator == (const Pair<K,V>& rhs) const {
        return  key == rhs.key;
    }

    bool operator != (const Pair<K,V>& rhs) const {
        return key != rhs.key;
    }
  
    bool operator < (const Pair<K,V>& rhs) const {
        return key < rhs.key;
    }
  
    bool operator > (const Pair<K,V>& rhs) const {
        return key > rhs.key;
    }

private:
    K key;
    V value;
};

#endif
