//-----------------------------------------------------------------------------
// File:	inventory.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: THe class process an action from the input file with the commands.
// The command is the char I for inventory. Inventory displays all the dvds in 
// inventory currently from the store.
//-----------------------------------------------------------------------------


#include "inventory.h"

// --------------------------------------------------------------------------
// Function:	Inventory::~Inventory()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Inventory::~Inventory()
{
}

// --------------------------------------------------------------------------
// Function:	bool Inventory::processAction(ifstream & inputFile, IStore * store)
// Title:	process the action of Inventory
// Description: parameter reads in the command inputFile and the DVD store. It will
// display the inventory that is currently held at the DVD store. It will first display
// the comedy movies in order followed by drama and ending with classical movies. The
// store calls its getree for each type in order to print them.
// Parameters:	ifstream & inputFile, IStore * store
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Inventory::processAction(ifstream & inputFile, IStore * store)
{
	bool temp = true;
	cout << "Store Inventory in order of Comedy, Drama, then Classic:" << endl;
	cout << "Comedy Movies:" << endl;
	store->getComedyTree().print();
	cout << "Drama Movies:" << endl;
	store->getDramaTree().print();
	cout << "Classical Movies:" << endl;
	store->getClassicalTree().print();
	return temp;
}
