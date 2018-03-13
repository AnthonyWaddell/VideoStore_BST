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
	comedyTree.makeEmpty();
	dramaTree.makeEmpty();
	classicalTree.makeEmpty();
	// delete m_customerHashPtr;// should write a make empty function for this
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
