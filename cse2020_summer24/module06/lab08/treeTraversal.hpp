/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 08
 * Date: June 21, 2024
 * 
 * Information:
 * This header file contains the function prototypes for the treeTraversal.cpp file.
 * The functions are used to print the elements of a binary tree in preorder, inorder, and postorder.
 * The clear function is used to delete the binary tree.
 * 
*/

// treeTraversal.hpp
#include<iostream>
using namespace std;

// BinaryNode struct
template <typename T>
struct BinaryNode {
	T data;
	BinaryNode* left;
	BinaryNode* right;
	  
	BinaryNode(const T & d = T()): data(d), left(nullptr), right(nullptr) { }	  
};

//print the elements of binary tree in preorder 
template <typename T>
void preorder(BinaryNode<T>* t) {
// add your code
    if (t != nullptr) {
        cout << t->data << " -> ";
        preorder(t->left);
        preorder(t->right);
    }
}

//print the elements of binary tree in inorder
template <typename T>
void inorder(BinaryNode<T>* t)  {
    if (t != nullptr) {
        inorder(t->left);
        cout << t->data << " -> ";
        inorder(t->right);
    }
}

//print the elements of binary tree in postorder 
template <typename T>
void postorder(BinaryNode<T>* t) {
    if (t != nullptr) {
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " -> ";
    }
}

//clear the binary tree by deleting the nodes
template <typename T>
void clear(BinaryNode<T>*& t) {
    if (t != nullptr) {
        clear(t->left);
        clear(t->right);
        delete t;
        t = nullptr; // Set the pointer to nullptr after deleting to avoid dangling pointer
    }
}