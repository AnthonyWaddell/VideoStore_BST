#include "inventory.h"

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
Inventory::~Inventory()
{
}

bool Inventory::processAction(ifstream & inputFile, IStore * store)
{
	bool temp = true;
	cout << store->getComedyTree();
	cout << store->getDramaTree();
	cout << store->getClassicalTree();
	return temp;
}
