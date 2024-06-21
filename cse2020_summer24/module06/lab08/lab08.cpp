/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 08
 * Date: June 21, 2024
 * 
 * This program creates a binary tree with char and int elements and calls three traversal functions to print elements.
 * 
*/

// lab08.cpp
#include <iostream>
#include <string>
#include "treeTraversal.hpp"

using namespace std;

// Create a binary tree with char elements
BinaryNode<char>* create_binary_tree() {
	BinaryNode<char>* node_A = new BinaryNode<char>('A');
	BinaryNode<char>* node_B = new BinaryNode<char>('B');
	BinaryNode<char>* node_C = new BinaryNode<char>('C'); 	
	BinaryNode<char>* node_D = new BinaryNode<char>('D');
	BinaryNode<char>* node_E = new BinaryNode<char>('E');

	// Create the binary tree
    node_A->left = node_B;
	node_A->right = node_C;
	node_B->left = node_D;
	node_B->right = node_E;
    
	return node_A;
}

// Create a binary tree with integer elements
BinaryNode<int>* create_binary_tree_int() {
	BinaryNode<int>* node1 = new BinaryNode<int>(1);
	BinaryNode<int>* node7 = new BinaryNode<int>(7);
	BinaryNode<int>* node3 = new BinaryNode<int>(3);
    BinaryNode<int>* node2 = new BinaryNode<int>(2);
    BinaryNode<int>* node6 = new BinaryNode<int>(6);
    BinaryNode<int>* node9 = new BinaryNode<int>(9);
    BinaryNode<int>* node5 = new BinaryNode<int>(5);
    BinaryNode<int>* node11 = new BinaryNode<int>(11);
    BinaryNode<int>* node4 = new BinaryNode<int>(4);
    
    // Create the binary tree
	node1->left = node7;
    node1->left->left = node2;
    node1->left->right = node6;
    node1->left->right->left = node5;
    node1->left->right->right = node11;
    node1->right = node3;
    node1->right->right = node9;
    node1->right->right->left = node4;
    
	return node1;
}

int main() {
    BinaryNode<char>* root = create_binary_tree();

    // Call three traversal functions to print elements
    cout << "Preorder traversal of char tree: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal of char tree: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal of char tree: ";
    postorder(root);
    cout << endl;

    // Clear the binary tree
    clear(root);

    BinaryNode<int>* root_int = create_binary_tree_int();

    // Call three traversal functions to print elements
    cout << "\nPreorder traversal of int tree: ";
    preorder(root_int);
    cout << endl;

    cout << "Inorder traversal of int tree: ";
    inorder(root_int);
    cout << endl;

    cout << "Postorder traversal of int tree: ";
    postorder(root_int);
    cout << endl;

    // Clear the binary tree
    clear(root_int);
}
