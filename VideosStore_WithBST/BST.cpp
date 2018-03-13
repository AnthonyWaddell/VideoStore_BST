//-----------------------------------------------------------------------------
// File:		BinTree.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
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
// Title:	Constructor
// Description: Constructs an empty BST object and sets root equal to NULL
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}

//-----------------------------------------------------------------------------
// Function:	BinTree::BinTree(const BinTree & other_tree)
// Title:	Copy Constructor
// Description: Constructs an empty BST object and sets equal to parameter tree
// Parameters:	const BinTree & other_tree; the other tree 
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
BinTree::BinTree(const BinTree &other_tree)
{
	root = NULL;
	*this = other_tree;
}

//-----------------------------------------------------------------------------
// Function:	BinTree::~BinTree(
// Title:	Destructor
// Description: Destructor for BST class object
// Parameters:	N/A
// Returns:	N/A
// History Log: 01/24/18 AW Completed Function
//-----------------------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

//-----------------------------------------------------------------------------
// Function:	bool BinTree::isEmpty() const
// Title:	boolean empty function
// Description: Tests to see if BST object is empty
// Parameters:	N/A
// Returns:	true if BST object is empty; false if not
// History Log: 03/14/18 AW Completed Function
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
// Title:	boolean empty function
// Description: Tests to see if BST object is empty
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmpty_Helper(root);
}

//-----------------------------------------------------------------------------
// Function:	void BinTree::makeEmpty_Helper(Node *&cur)
// Title:	Helper function for makeEmpty
// Description: Clears data pointed to by BST nodes and then deletes node until
//					BST is empty in post order traversal
// Parameters:	Node *&cur; the current node to delete
// Returns:	void
// History Log: 03/14/18 AW Completed Function
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
// Function:	bool BinTree::insertComedy(Node *& cur, DVD * datum)
// Title:	insert method for comedy tree
// Description: insert comedy item (DVD) into comedy tree
// Parameters:	Node *& cur, DVD * datum
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::insertComedy(Node *& cur, DVD * datum)
{
	bool inserted = false; //track if item has been inserted or not
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
// Function:	bool BinTree::insertDrama(Node *& cur, DVD * datum)
// Title:	insert method for drama tree
// Description: insert drama item (DVD) into drama tree
// Parameters:	Node *& cur, DVD * datum
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::insertDrama(Node *& cur, DVD * datum)
{
	bool inserted = false; //track if item has been inserted or not
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
// Function:	bool BinTree::insertClassical(Node *& cur, DVD * datum)
// Title:	insert method for classical tree
// Description: insert classical item (DVD) into classical tree
// Parameters:	Node *& cur, DVD * datum
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::insertClassical(Node *& cur, DVD * datum)
{
	bool inserted = false; //track if item has been inserted or not
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
// Function:	bool BinTree::returnComedy(string m_title, int m_year, Node *& cur)
// Title:	return movie of comedy inventory
// Description: will check comedy tree to return movie and increase the stock of movie if found
// Parameters:	string m_title, int m_year, Node *& cur
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::returnComedy(string m_title, int m_year, Node *& cur) const
{
	bool return_value = false;
	int one_copy = 1;

	if (cur == NULL)
	{
		return false;
	}
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
// Function:	bool BinTree::returnDrama(string m_title, int m_year, Node *& cur)
// Title:	return movie from drama inventory
// Description: will check drama tree to return movie and increase the stock of movie if found
// Parameters:	string m_title, int m_year, Node *& cur
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::returnDrama(string m_director, string m_title, Node *& cur) const
{
	bool return_value = false;
	int one_copy = 1;

	if (cur == NULL)
	{
		return false;
	}
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
// Function:	bool BinTree::returnClassical(int m_month, int m_year, string m_first, string m_last, Node *& cur)
// Title:	return movie from classical inventory
// Description: will check classical tree to return movie and increase the stock of movie if found
// but classical will check by release data, then major actor.
// Parameters:	int m_month, int m_year, string m_first, string m_last, Node *& cur
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
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
		//if (cur->left_child->data->getYearReleased() == m_year &&
		//	static_cast<Classical*>(cur->left_child->data)->getMonthReleased() == m_month)
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
// Function:	bool BinTree::borrowComedy(string m_title, int m_year, Node *& cur)
// Title:	borrow movie from comedy inventory 
// Description: check the comedy inventory tree and decrement stock of movie by one
// Parameters:	string m_title, int m_year, Node *& cur
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::borrowComedy(string m_title, int m_year, Node *& cur) const
{
	bool return_value = false;
	int one_copy = -1;

	if (cur == NULL)
	{
		return false;
	}
	// If it's less than this nodes movie data
	if (m_title < cur->data->getTitle())
	{
		return borrowComedy(m_title, m_year, cur->left_child);
	}
	// If it is this nodes movie data, decrement the stock and return
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
		return borrowComedy(m_title, m_year, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
// Function:	bool BinTree::borrowDrama(string m_title, int m_year, Node *& cur)
// Title:	borrow movie from drama inventory 
// Description: check the drama inventory tree and decrement stock of movie by one
// Parameters:	string m_title, int m_year, Node *& cur
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::borrowDrama(string m_director, string m_title, Node *& cur) const
{
	bool return_value = false;
	int one_copy = -1;

	if (cur == NULL)
	{
		return false;
	}
	// If it's less than this nodes movie data
	if (m_director < cur->data->getDirector())
	{
		return borrowDrama(m_director, m_title, cur->left_child);
	}
	// If it is this nodes movie data, decrement the stock and return
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
		return borrowDrama(m_director, m_title, cur->right_child);
	}

	return return_value;
}

//-----------------------------------------------------------------------------
// Function:	bool BinTree::borrowDrama(int m_month, int m_year, string m_first, string m_last, Node *& cur)
// Title:	borrow movie from classical inventory 
// Description: check the classcial inventory tree and decrement stock of movie by one
// Parameters:	int m_month, int m_year, string m_first, string m_last, Node *& cur
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::borrowClassical(int m_month, int m_year, string m_first, string m_last, Node *& cur) const
{
	bool return_value = false;
	int one_copy = -1;

	if (cur == NULL)
	{
		return false;
	}
	// If it's less than this nodes movie data
	if (m_year < cur->data->getYearReleased())
	{
		return borrowClassical(m_month, m_year, m_first, m_last, cur->left_child);
	}
	// If it is this nodes movie data, decrement the stock and return
	else if (cur->data->getYearReleased() == m_year && static_cast<Classical*>(cur->data)->getMonthReleased() == m_month)
	{

		// This should probably call this function again on the left & right child of this node?
		int currentStock = cur->data->getStock();
		if (cur->data->getStock() >= 1)
		{
			cur->data->setStock(currentStock + one_copy);
			// Check for same movie, different actor
			//if (cur->left_child->data->getYearReleased() == m_year &&
			//	static_cast<Classical*>(cur->left_child->data)->getMonthReleased() == m_month)
			//{
			//	cur->left_child->data->setStock(currentStock + one_copy);
			//}
			//if (cur->right_child->data->getYearReleased() == m_year &&
			//	static_cast<Classical*>(cur->right_child->data)->getMonthReleased() == m_month)
			//{
			//	cur->right_child->data->setStock(currentStock + one_copy);
			//}
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
		return borrowClassical(m_month, m_year, m_first, m_last, cur->right_child);
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

//-----------------------------------------------------------------------------
// Function:	void BinTree::print()
// Title:	display the tree
// Description: uses the inorder_Helper function which displays every node in a tree
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
void BinTree::print() const
{
	inorder_Helper(root);
}

//-----------------------------------------------------------------------------
// Function:	void BinTree::inorder_Helper(Node *cur)
// Title:	helps display data in tree
// Description: this is a helper function tahat recurses through the tree to display the data
// Parameters:	Node *cur
// Returns:	void
// History Log: 03/14/18 AW Completed Function
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
// Function:	bool BinTree::contains(const string title)
// Title:	check tree if it has a title
// Description: method calls a helper function that checks to see if a node contains
//		a specific movie title
// Parameters:	const string title
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
//-----------------------------------------------------------------------------
bool BinTree::contains(const string title)
{
	bool contains = false;
	contains = contains_helper(root, title);
	return contains;
}

//-----------------------------------------------------------------------------
// Function:	bool BinTree::contains_helper(Node * cur, const string title)
// Title:	helper method to check movie title
// Description: helper function that checks to see if a node contains
//		a specific movie title
// Parameters:	Node * cur, const string title
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
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
