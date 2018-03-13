//-----------------------------------------------------------------------------
// File:	node.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class creates a node class with item pointer and next pointer.
// The class allows to get and set the current and next pointer.
//-----------------------------------------------------------------------------


#include "node.h"

// --------------------------------------------------------------------------
// Function:	Node::Node()
// Title:	Contructor
// Description: Contructor that sets the itemptr and next node ptr to NULL
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Node::Node()
{
	m_itemPtr = NULL;
	m_nextNodePtr = NULL;
}

// --------------------------------------------------------------------------
// Function:	Node::Node()
// Title:	node constructor w/ content param
// Description: Contructor that sets the itemptr the itmptr and next node ptr to NULL
// Parameters:	IItem * itemPtr
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Node::Node(IItem * itemPtr)
{
	m_itemPtr = itemPtr;
	m_nextNodePtr = NULL;
}

// --------------------------------------------------------------------------
// Function:	Node::Node(IItem * itemPtr, Node * nextNodePtr)
// Title:	node constructor w/ content param 
// Description: Contructor that sets the itemptr and next node ptr 
// Parameters:	IItem * itemPtr
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Node::Node(IItem * itemPtr, Node * nextNodePtr)
{
	m_itemPtr = itemPtr;
	m_nextNodePtr = nextNodePtr;
}

// --------------------------------------------------------------------------
// Function:	Node::~Node()
// Title:	node destructor
// Description: Destructor that sets the itemptr to NULL
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Node::~Node()
{
	if (m_itemPtr != NULL)
	{
		m_itemPtr = NULL;
	}
}

// --------------------------------------------------------------------------
// Function:	IItem * Node::getItemPtr()
// Title:	accessor for m_itemPtr
// Description: get the itemptr
// Parameters:	N/A
// Returns:	IItem
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IItem * Node::getItemPtr()
{
	IItem * temp = this->m_itemPtr;
	return temp;
}

// --------------------------------------------------------------------------
// Function:	Node * Node::getNextPtr()
// Title:	accessor for m_nextNodePtr 
// Description: get the nextNode pointer
// Parameters:	N/A
// Returns:	Node
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Node * Node::getNextPtr()
{
	Node *temp = this->m_nextNodePtr;
	return temp;
}

// --------------------------------------------------------------------------
// Function:	void Node::setNextPtr(Node * nextPtr)
// Title:	mutator for next node pointer  
// Description: set the next pointer 
// Parameters:	Node * nextPtr
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Node::setNextPtr(Node * nextPtr)
{
	this->m_nextNodePtr = nextPtr;
}

// --------------------------------------------------------------------------
// 
// Function:	void Node::setItemPtr(IItem * itemPtr)
// Title:	mutator for next node pointer   
// Description: set the item pointer
// Parameters:	IItem * itemPtr
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Node::setItemPtr(IItem * itemPtr)
{
	this->m_itemPtr = itemPtr;
}
