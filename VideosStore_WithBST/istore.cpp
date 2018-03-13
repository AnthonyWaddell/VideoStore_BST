//-----------------------------------------------------------------------------
// File:	istore.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The istore is a class to create a store that has customers in 
// its database and has inventory of comedy, drama, and classical types
//-----------------------------------------------------------------------------

#include "istore.h"

// --------------------------------------------------------------------------
// Function:	IStore::IStore()
// Title:	Constructor
// Description: Contructor that creates a hashtable of a customers
// Parameters:	N/a
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IStore::IStore()
{
	Hash *holdCustomers = new Hash();
}

// --------------------------------------------------------------------------
// Function:	IStore::~IStore()
// Title:	Destructor
// Description: Destructor to delete the hash pointer
// Parameters:	N/a
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IStore::~IStore()
{
	comedyTree.makeEmpty();
	dramaTree.makeEmpty();
	classicalTree.makeEmpty();
	m_customerHashPtr.makeEmpty();
}

// --------------------------------------------------------------------------
// Function:	const Hash & IStore::getCustomerHashTablePtr()
// Title:	get customer hashtable
// Description: method returns the customer hashtable
// Parameters:	N/A
// Returns:	Hash
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
const Hash & IStore::getCustomerHashTablePtr() const
{
	return m_customerHashPtr;
}

// --------------------------------------------------------------------------
// Function:	BinTree & IStore::getComedyTree() 
// Title:	accessor for comedyTree
// Description: Method returns the comedy tree which holds comedy dvd types
// Parameters:	N/A
// Returns:	BinTree
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
BinTree & IStore::getComedyTree() 
{
	return comedyTree; 
}

// --------------------------------------------------------------------------
// Function:	BinTree & IStore::getDramaTree() 
// Title:	accessor for dramaTree
// Description: returns the drama tree which holds drama dvd types
// Parameters:	N/A
// Returns:	BinTree
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
BinTree & IStore::getDramaTree() 
{
	return dramaTree;
}

// --------------------------------------------------------------------------
// Function:	BinTree & IStore::getClassicalTree()
// Title:	accessor for classicalTree
// Description: returns the classical tree which holds classical dvd types
// Parameters:	N/A
// Returns:	BinTree
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
BinTree & IStore::getClassicalTree()
{
	return classicalTree;
}
