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
	cout << "Store Inventory in order of Comedy, Drama, then Classic:" << endl;
	cout << "Comedy Movies:" << endl;
	cout << store->getComedyTree();
	cout << "Drama Movies:" << endl;
	cout << store->getDramaTree();
	cout << "Classical Movies:" << endl;
	cout << store->getClassicalTree();
	return temp;
}
