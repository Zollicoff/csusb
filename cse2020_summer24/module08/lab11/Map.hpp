// Map.cpp
// after Mark A. Weiss, Kerstin Voigt

#ifndef MAP_HPP
#define MAP_HPP

#include "Pair.hpp"
#include "MapSet.hpp"     // must have insert that returns iterator!!!

using namespace std;

template <typename K, typename V>

class Map {
public:
    Map() {}

    void printMap() {
        typename Set< Pair<K,V> >::iterator itr = themap.begin();
        for (; itr != themap.end(); ++itr)
        {
        cout << (*itr).getKey() << ":" << (*itr).getValue() << endl;
        }
        return;
    }

    V & operator [](K key) {
        typename Set<Pair<K,V> >::iterator here;
        Pair<K,V> probe(key, V());
        here = themap.insert(probe);
        return (*here).getValue();
    }

    void remove(K & key) {
        Pair<K,V> probe;
        probe.setKey(key);
        themap.remove(probe);

        return;
    }
    
private:
        Set<Pair<K,V> > themap;
};

#endif
