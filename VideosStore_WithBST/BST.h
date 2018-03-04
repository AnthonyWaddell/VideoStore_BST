#ifndef BINTREE_H
#define BINTREE_H
//----------------------------------------------------------------------------
// File: Poly.h
// 
// Description: Function outlines for the Poly class
// 
// Programmer:	Anthony Waddell
// 
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015, g++
//---------------------------------------------------------------------------
#include "node.h"
#include "dvd.h"
#include "comedy.h"
#include "drama.h"
#include "classical.h"
#include <algorithm>

using namespace std;

class BinTree
{
private:

	// Node to contain data and fill in tree
	struct Node
	{
		DVD* data;						// pointer to data object
		Node* left_child;					// left subtree pointer
		Node* right_child;					// right subtree pointer
	};
	Node* root;								// root of the tree

public:

	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	Node*& getRoot() { return root; }
											// Make Empty function and helper
	void makeEmpty();						// make the tree empty so isEmpty returns true
	void makeEmpty_Helper(Node *&cur);

	// Insert function and helper
	bool insertComedy(Node *& cur, DVD *datum);
	bool insertDrama(Node *& cur, DVD *datum);
	bool insertClassical(Node *& cur, DVD *datum);

	// Overloaded output operator and helper function
	friend ostream & operator<<(ostream &sout, BinTree &tree);
	void inorder_Helper(Node *cur) const;
};
#endif