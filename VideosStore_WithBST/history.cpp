//-----------------------------------------------------------------------------
// File:	history.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: History class is an action class that comes from the factory 
// which takes in actions that should be done. It will read the rest of the line
// which is just the customers id and get the customer's history.
//-----------------------------------------------------------------------------

#include "history.h"
#include <iostream>

using namespace std;


// --------------------------------------------------------------------------
// Function:	History::~History()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
History::~History()
{
}

// ---------------------------- processAction -------------------------------
// Function:	bool History::processAction(std::ifstream& inputFile, IStore* store)
// Title:	Processes the history action reading what to do from a input file.
// Description: A valid IStore object. Correctly formatted input file line.
// Postconditions: Input file ifstream will be at the end of the line.
// Prints to the screen the customers history, if valid customer.
// Parameters:	inputFile - A input file with lines of properly formatted
// commands.
// Returns:	Returns true if history displaying was successful, and false 
// otherwise (invalid customer).
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool History::processAction(std::ifstream& inputFile, IStore* store)
{
	char action = ' '; 
	string badData;
	int id;
	int key;
	bool returnValue;

	//inputFile >> action;
	inputFile >> id;

	key = store->getCustomerHashTablePtr().generateHashKey(id);
	if (store->getCustomerHashTablePtr().retrieve(key) == NULL)
	{
		cout << "Incorrect Customer ID." << endl;
		getline(inputFile, badData); //get the rest of the data of the wrong ID
		returnValue = false;
				
	}
	else if (store->getCustomerHashTablePtr().retrieve(key) != NULL)
	{
		Customer* historyPerson = store->getCustomerHashTablePtr().retrieve(key);
		cout << historyPerson->getFirstName()  << " " << historyPerson->getLastName() << ":" << endl;
		historyPerson->getDVDHistory();
		returnValue = true;
	}

	return returnValue;
}
