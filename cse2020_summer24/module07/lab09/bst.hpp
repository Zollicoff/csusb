/*
 * Name: Zachary A. Hampton
 * Student ID: 008339494
 * Assignment: Lab 09
 * Date: June 21, 2024
 * 
 * This header file contains the BinarySearchTree class template that is used to create a 
 * binary search tree with int and string elements and call three functions to print elements 
 * and elements within a range.
 * 
*/

// bst.cpp
#ifndef BST_HPP
#define BST_HPP

#include <cassert>
#include <iostream>
#include <string>
using namespace std;         

template <typename C>
class BinarySearchTree {
public:
    BinarySearchTree( ) : root(nullptr) {  }

    ~BinarySearchTree( ) { 
        makeEmpty();
    }

    const C & findMin( ) const {
      assert(!isEmpty());
      return findMin( root )->element;
    }

    const C & findMax( ) const {
      assert(!isEmpty());
      return findMax( root )->element;
    }

    bool contains( const C & x ) const {
        return contains( x, root );
    }

    bool isEmpty( ) const {
        return root == nullptr;
    }

    void printBST( ) const {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printBST( root );
    }

    void makeEmpty( ) {
        makeEmpty( root );
    }
    
    void insert( const C & x ) {
        insert( x, root );
    }     

    void remove( const C & x ) {
        remove( x, root );
    }

    // Activity 3 add Public Print Range Function
    void printRange(const C & k1, const C & k2) const {
        printRange(root, k1, k2);
    }

private:
struct BinaryNode {
      C element;
      BinaryNode* left;
      BinaryNode* right;

      BinaryNode( const C & theElement, BinaryNode* lt, BinaryNode* rt )
            : element( theElement ), left( lt ), right( rt ) { }
   };
      
   BinaryNode* root;

    // Internal method to find the smallest item in a subtree t.
    // Return node containing the smallest item.    
    BinaryNode* findMin( BinaryNode* t ) const {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }
    
    // Internal method to find the largest item in a subtree t.
    // Return node containing the largest item.
    BinaryNode* findMax( BinaryNode* t ) const {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }

    // Internal method to test if an item is in a subtree.
    // x is item to search for.
    // t is the node that roots the subtree.    
    bool contains( const C & x, BinaryNode* t ) const {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }

    void printBST( BinaryNode* t) const {
        if( t != nullptr ) {
            printBST( t->left );
            cout << t->element << " - ";
            printBST( t->right );
        }
    }

    void makeEmpty( BinaryNode* & t ) {
        if( t != nullptr ) {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
    
    // Internal method to insert into a subtree.
    // x is the item to insert.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.    
    void insert( const C & x, BinaryNode* & t ) {
        if( t == nullptr )
            t = new BinaryNode( x, nullptr, nullptr );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    
    // Internal method to remove from a subtree.
    // x is the item to remove.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.    
    void remove( const C & x, BinaryNode* & t ) {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) { // Two children
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        } else {
            BinaryNode* oldNode = t;
            if ( t->left == nullptr )
                t = t->right;
            else
                t = t->left;
            delete oldNode;
        }
    }

    void printRange(BinaryNode* t, const C & k1, const C & k2) const {
	// TODO - add your code
        if (t == nullptr) return;

        if (k1 < t->element)
            printRange(t->left, k1, k2);

        if (k1 < t->element && t->element < k2)
            cout << t->element << " - ";

        if (t->element < k2)
            printRange(t->right, k1, k2);    
    }
};

#endif
