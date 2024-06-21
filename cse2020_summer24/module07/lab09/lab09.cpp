/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 09
 * Date: June 21, 2024
 * 
 * This program creates a binary search tree with int and string elements
 * and calls three functions to print elements and elements within a range.
 *  
*/

// lab09.cpp
#include <iostream>
#include <string>
#include "bst.hpp"

using namespace std;

int main() {
	BinarySearchTree<int> bst; // create a binary search tree with int elements
	int x = 0;
	
	cout << "Enter the elements to be added (stop when entering 0): " << endl;
	cin >> x;
    while (x!= 0) {
        bst.insert(x);
        cin >> x;
    }
	
    cout << endl << "Print the values:" << endl;
	bst.printBST();
    cout << endl;

	cout << endl << "Enter elements to be removed (stop when entering 0): " << endl;
	cin >> x;
    while (x!= 0) {
        bst.remove(x);
        cin >> x;
    }
    
    cout << endl << "Print the values:" << endl;
	bst.printBST();\
    cout << endl;

	//Activity 3
    int k1 = 0, k2 = 0;
	cout << endl << "Please enter the range: ";
	cin >> k1 >> k2;
    
    cout << endl << "Print the elements between the range:" << endl;
    bst.printRange(k1, k2);
    cout << endl;

    BinarySearchTree<string> bststr; // create a binary search tree with string elements
	string s = "";
	
	cout << endl << "Enter the strings to be added (stop when entering \"exit\"): " << endl;
    cin >> s;
    while (s != "exit") {
        bststr.insert(s);
        cin >> s;
    }
	
    cout << endl << "Print the values:" << endl;
	bststr.printBST();
	cout << endl;

    return 0;
}
