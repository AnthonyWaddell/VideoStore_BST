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
	store->getComedyTree().print();
	cout << "Drama Movies:" << endl;
	store->getDramaTree().print();
	cout << "Classical Movies:" << endl;
	store->getClassicalTree();
	return temp;
}
