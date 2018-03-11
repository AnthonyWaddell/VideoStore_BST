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
const BinTree & IStore::getComedyTree() const
{
	return comedyTree; 
}

// --------------------------------------------------------------------------
// accessor for dramaTree
// --------------------------------------------------------------------------
const BinTree & IStore::getDramaTree() const
{
	return dramaTree;
}

// --------------------------------------------------------------------------
// accessor for classicalTree
// --------------------------------------------------------------------------
const BinTree & IStore::getClassicalTree() const
{
	return classicalTree;
}
