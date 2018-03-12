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
	Comedy *temp = static_cast<Comedy*>(datum);

	// Insert when empty spot is found
	if (cur == NULL)
	{
		// I think this might cause a memory leak since root is already established as a node, we'll see lol
		cur = new Node;
		cur->data = datum;
		cur->left_child = NULL;
		cur->right_child = NULL;
		inserted = true;
	}

	// Duplicate node found, do not insert
	else if (*temp == *&cur->data)
	{
		inserted = false;
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
	return inserted;
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
		// might cause memory leak since root is already established as a node, we'll see lol
		cur = new Node;
		cur->data = datum;
		cur->left_child = NULL;
		cur->right_child = NULL;
		inserted = true;
	}

	// Duplicate node found, do not insert
	else if (*temp == *&cur->data)
	{
		inserted = false;
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
	return inserted;
}

//-----------------------------------------------------------------------------
// insert classical into classical tree
//-----------------------------------------------------------------------------
bool BinTree::insertClassical(Node *& cur, DVD * datum)
{
	bool inserted = false;
	int position = 0;
	Classical *temp = static_cast<Classical*>(datum);

	// Insert when empty spot is found
	if (cur == NULL)
	{
		cur = new Node;
		cur->data = datum;
		cur->left_child = NULL;
		cur->right_child = NULL;
		inserted = true;
	}

	// Duplicate node found, do not insert
	else if (*temp == *&cur->data)
	{
		inserted = false;
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
	return inserted;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::returnComedy(string m_title, int m_year, Node *& cur) const
{
	bool return_value = false;
	int one_copy = 1;

	// If it's less than this nodes movie data
	if (m_title < cur->data->getTitle())
	{
		return returnComedy(m_title, m_year, cur->left_child);
	}
	// If it is this nodes movie data, increment the stock and return
	else if (cur->data->getTitle() == m_title && cur->data->getYearReleased() == m_year)
	{
		int currentStock = cur->data->getStock();
		cur->data->setStock(currentStock + one_copy);
		return_value = true;
	}
	// If it's greater than this nodes movie data;
	else
	{
		return returnComedy(m_title, m_year, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::returnDrama(string m_director, string m_title, Node *& cur) const
{
	bool return_value = false;
	int one_copy = 1;

	// If it's less than this nodes movie data
	if (m_director < cur->data->getDirector())
	{
		return returnDrama(m_director, m_title, cur->left_child);
	}
	// If it is this nodes movie data, increment the stock and return
	else if (cur->data->getDirector() == m_director && cur->data->getTitle() == m_title)
	{
		int currentStock = cur->data->getStock();
		cur->data->setStock(currentStock + one_copy);
		return_value = true;
	}
	// If it's greater than this nodes movie data;
	else
	{
		return returnDrama(m_director, m_title, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
//  -	classics (C) are sorted by Release date, then Major actor
//-----------------------------------------------------------------------------
bool BinTree::returnClassical(int m_month, int m_year, string m_first, string m_last, Node *& cur) const
{
	bool return_value = false;
	int one_copy = 1;

	if (cur == NULL)
	{
		return false;
	}
	// If it's less than this nodes movie data
	if (m_year < cur->data->getYearReleased())
	{
		return returnClassical(m_month, m_year, m_first, m_last, cur->left_child);
	}
	// If it is this nodes movie data, increment the stock and return
	else if (cur->data->getYearReleased() == m_year && static_cast<Classical*>(cur->data)->getMonthReleased() == m_month)
	{

		// This should probably call this function again on the left & right child of this node?
		int currentStock = cur->data->getStock();
		cur->data->setStock(currentStock + one_copy);
		// Check for same movie, different actor
		if (cur->left_child->data->getYearReleased() == m_year &&
			static_cast<Classical*>(cur->left_child->data)->getMonthReleased() == m_month)
			return_value = true;

	}
	// If it's greater than this nodes movie data;
	else
	{
		return returnClassical(m_month, m_year, m_first, m_last, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::borrowComedy(string m_title, int m_year, Node *& cur) const
{
	bool return_value = false;
	int one_copy = -1;

	// If it's less than this nodes movie data
	if (m_title < cur->data->getTitle())
	{
		return returnComedy(m_title, m_year, cur->left_child);
	}
	// If it is this nodes movie data, increment the stock and return
	else if (cur->data->getTitle() == m_title && cur->data->getYearReleased() == m_year)
	{
		int currentStock = cur->data->getStock();
		if (cur->data->getStock() >= 1)
		{
			cur->data->setStock(currentStock + one_copy);
			return_value = true;
		}
		else
		{
			cout << "Error: Out of stock, please check back soon." << endl;
		}
	}
	// If it's greater than this nodes movie data;
	else
	{
		return returnComedy(m_title, m_year, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::borrowDrama(string m_director, string m_title, Node *& cur) const
{
	bool return_value = false;
	int one_copy = -1;

	// If it's less than this nodes movie data
	if (m_director < cur->data->getDirector())
	{
		return returnDrama(m_director, m_title, cur->left_child);
	}
	// If it is this nodes movie data, increment the stock and return
	else if (cur->data->getDirector() == m_director && cur->data->getTitle() == m_title)
	{
		int currentStock = cur->data->getStock();
		if (cur->data->getStock() >= 1)
		{
			cur->data->setStock(currentStock + one_copy);
			return_value = true;
		}
		else
		{
			cout << "Error: Out of stock, please check back soon." << endl;
		}
	}
	// If it's greater than this nodes movie data;
	else
	{
		return returnDrama(m_director, m_title, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::borrowClassical(int m_month, int m_year, string m_first, string m_last, Node *& cur) const
{
	bool return_value = false;
	int one_copy = -1;

	// If it's less than this nodes movie data
	if (m_year < cur->data->getYearReleased())
	{
		return returnClassical(m_month, m_year, m_first, m_last, cur->left_child);
	}
	// If it is this nodes movie data, increment the stock and return
	else if (cur->data->getYearReleased() == m_year && static_cast<Classical*>(cur->data)->getMonthReleased() == m_month)
	{

		// This should probably call this function again on the left & right child of this node?
		int currentStock = cur->data->getStock();
		if (cur->data->getStock() >= 1)
		{
			cur->data->setStock(currentStock + one_copy);
			// Check for same movie, different actor
			if (cur->left_child->data->getYearReleased() == m_year &&
				static_cast<Classical*>(cur->left_child->data)->getMonthReleased() == m_month)
			{
				cur->left_child->data->setStock(currentStock + one_copy);
			}
			if (cur->right_child->data->getYearReleased() == m_year &&
				static_cast<Classical*>(cur->right_child->data)->getMonthReleased() == m_month)
			{
				cur->right_child->data->setStock(currentStock + one_copy);
			}
			return_value = true;
		}
		else
		{
			cout << "Error: Out of stock, please check back soon." << endl;
		}
	}
	// If it's greater than this nodes movie data;
	else
	{
		return returnClassical(m_month, m_year, m_first, m_last, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
//ostream &operator<<(ostream &sout, BinTree &tree)
//{
//	tree.inorder_Helper(tree.root);
//	cout << endl;
//	return sout;
//}

void BinTree::print() const
{
	inorder_Helper(root);
}

//-----------------------------------------------------------------------------
//
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
		cur->data->display();
		// Move down right subtree
		inorder_Helper(cur->right_child);
	}
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::contains(const string title)
{
	bool contains = false;
	contains = contains_helper(root, title);
	return contains;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool BinTree::contains_helper(Node * cur, const string title)
{
	if (cur == NULL)
	{
		return false;
	}
	if (title < cur->data->getTitle())
	{
		return contains_helper(cur->left_child, title);
	}
	else if (title == cur->data->getTitle())
	{
		return true;
	}
	else
	{
		return contains_helper(cur->right_child, title);
	}
}
