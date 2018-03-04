//-----------------------------------------------------------------------------
// File:		BinTree.cpp
// Programmer:	Anthony Waddell
// Resources:
//		for getHeight https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
//			and https://stackoverflow.com/questions/2597637/finding-height-in-binary-search-tree
//		for bsttoarray
//			https://stackoverflow.com/questions/22103718/binary-tree-to-array-wrong-values-inserted-into-array
//		for arraytobst
//			https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
//-----------------------------------------------------------------------------
#include "BST.h"
using namespace std;

//-----------------------------------------------------------------------------
// Function:	BinTree::BinTree()
// Title:		Constructor
// Description: Constructs an empty BST object and sets root equal to NULL
//
// Programmer:	Anthony Waddell
//
// Parameters:	N/A
// Returns:		N/A
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}

//-----------------------------------------------------------------------------
// Function:	BinTree::BinTree(const BinTree & other_tree)
// Title:		Copy Constructor
// Description: Constructs an empty BST object and sets equal to parameter tree
//
// Programmer:	Anthony Waddell
//
// Parameters:	const BinTree & other_tree; the other tree 
// Returns:		N/A
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
BinTree::BinTree(const BinTree &other_tree)
{
	root = NULL;
	*this = other_tree;
}

//-----------------------------------------------------------------------------
// Function:	BinTree::~BinTree(
// Title:		Destructor
// Description: Destructor for BST class object
//
// Programmer:	Anthony Waddell
//
// Parameters:	N/A
// Returns:		N/A
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

//-----------------------------------------------------------------------------
// Function:	bool BinTree::isEmpty() const
// Title:		boolean empty function
// Description: Tests to see if BST object is empty
//
// Programmer:	Anthony Waddell
//
// Parameters:	N/A
// Returns:		true if BST object is empty; false if not
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	bool empty;
	// If tree is empty
	if (root == NULL)
	{
		empty = true;
	}
	// Tree is not empy
	else
	{
		empty = false;
	}
	return empty;
}


//-----------------------------------------------------------------------------
// Function:	bool BinTree::isEmpty() const
// Title:		boolean empty function
// Description: Tests to see if BST object is empty
//
// Programmer:	Anthony Waddell
//
// Parameters:	N/A
// Returns:		void
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmpty_Helper(root);
}

//-----------------------------------------------------------------------------
// Function:	void BinTree::makeEmpty_Helper(Node *&cur)
// Title:		Helper function for makeEmpty
// Description: Clears data pointed to by BST nodes and then deletes node until
//					BST is empty in post order traversal
//
// Programmer:	Anthony Waddell
//
// Parameters:	Node *&cur; the current node to delete
// Returns:		void
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
void BinTree::makeEmpty_Helper(Node *&cur)
{
	// If node doesn't exist
	if (cur == NULL)
	{
		return;
	}
	// Recursively empy tree from left to right
	makeEmpty_Helper(cur->left_child);
	makeEmpty_Helper(cur->right_child);
	// Delete DVD pointed to by node
	if (cur->data != NULL)
	{
		delete cur->data;
		cur->data = NULL;
	}
	// Delete node
	delete cur;
	cur = NULL;
}


//-----------------------------------------------------------------------------
// insert comedy item into comedy tree
//-----------------------------------------------------------------------------
bool BinTree::insertComedy(Node *& cur, DVD * datum)
{
	bool inserted = false;
	int position = 0;
	Comedy *temp = static_cast<Comedy*>(datum);

	// Insert when empty spot is found
	if (cur == NULL)
	{
		cur = new Node;
		cur->data = datum;
		cur->left_child = NULL;
		cur->right_child = NULL;
		// If tree is empty, this is root node
		if (isEmpty())
		{
			root = cur;
		}
		return true;
	}

	// Duplicate node found, do not insert
	else if (*temp == *&cur->data)
	{
		return false;
	}
	// Insert left for smaller data value
	else if (*datum < &*cur->data)
	{
		insertComedy(cur->left_child, datum);
	}
	// Insert right for larger data value
	else
	{
		insertComedy(cur->right_child, datum);
	}
}

//-----------------------------------------------------------------------------
// insert drama into drama tree
//-----------------------------------------------------------------------------
bool BinTree::insertDrama(Node *& cur, DVD * datum)
{
	bool inserted = false;
	int position = 0;
	Drama *temp = static_cast<Drama*>(datum);

	// Insert when empty spot is found
	if (cur == NULL)
	{
		cur = new Node;
		cur->data = datum;
		cur->left_child = NULL;
		cur->right_child = NULL;
		// If tree is empty, this is root node
		if (isEmpty())
		{
			root = cur;
		}
		return true;
	}

	// Duplicate node found, do not insert
	else if (*temp == *&cur->data)
	{
		return false;
	}
	// Insert left for smaller data value
	else if (*datum < &*cur->data)
	{
		insertDrama(cur->left_child, datum);
	}
	// Insert right for larger data value
	else
	{
		insertDrama(cur->right_child, datum);
	}
}

//-----------------------------------------------------------------------------
// insert classical into classical tree
//-----------------------------------------------------------------------------
bool BinTree::insertClassical(Node *& cur, DVD * datum)
{
	bool inserted = false;
	int position = 0;
	Drama *temp = static_cast<Drama*>(datum);

	// Insert when empty spot is found
	if (cur == NULL)
	{
		cur = new Node;
		cur->data = datum;
		cur->left_child = NULL;
		cur->right_child = NULL;
		// If tree is empty, this is root node
		if (isEmpty())
		{
			root = cur;
		}
		return true;
	}

	// Duplicate node found, do not insert
	else if (*temp == *&cur->data)
	{
		return false;
	}
	// Insert left for smaller data value
	else if (*datum < &*cur->data)
	{
		insertClassical(cur->left_child, datum);
	}
	// Insert right for larger data value
	else
	{
		insertClassical(cur->right_child, datum);
	}
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
ostream &operator<<(ostream &sout, BinTree &tree)
{
	tree.inorder_Helper(tree.root);
	cout << endl;
	return sout;
}

//-----------------------------------------------------------------------------
// Function:	void BinTree::inorder_Helper(Node *cur) const
// Title:		Helper function for overloaded output operator of BST class
// Description: Prints out in order traversal of BST object
// Programmer:	Anthony Waddell
//
// Parameters:	Node *cur; the cureent node
// Returns:		void
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
void BinTree::inorder_Helper(Node *cur) const
{
	if (cur == NULL)
	{
		return;
	}
	else
	{
		// Move down left subtree
		inorder_Helper(cur->left_child);
		// Display data
		cur->data->display(cout);
		// Move down right subtree
		inorder_Helper(cur->right_child);
	}
}
