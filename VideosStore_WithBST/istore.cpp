#include "istore.h"

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
IStore::IStore()
{
	Hash *holdCustomers = new Hash();
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
IStore::~IStore()
{
	// I'm like 99% sure this will cause a fat memory leak
	//delete m_customerHashPtr;
}



const Hash & IStore::getCustomerHashTablePtr() const
{
	return m_customerHashPtr;
}

// --------------------------------------------------------------------------
// accessor for comedyTree
// --------------------------------------------------------------------------
BinTree & IStore::getComedyTree() 
{
	return comedyTree; 
}

// --------------------------------------------------------------------------
// accessor for dramaTree
// --------------------------------------------------------------------------
BinTree & IStore::getDramaTree() 
{
	return dramaTree;
}

// --------------------------------------------------------------------------
// accessor for classicalTree
// --------------------------------------------------------------------------
BinTree & IStore::getClassicalTree()
{
	return classicalTree;
}
