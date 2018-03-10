#include "history.h"
#include <iostream>

using namespace std;


// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
History::~History()
{
}


// ---------------------------- processAction -------------------------------
// Processes the history action reading what to do from a input file.
// Preconditions: A valid IStore object. Correctly formatted input file line.
// Postconditions: Input file ifstream will be at the end of the line.
// Prints to the screen the customers history, if valid customer.
// Parameter: inputFile - A input file with lines of properly formatted
// commands.
// store - An IStore object.
// Return: Returns true if history displaying was successful, and false 
// otherwise (invalid customer).
// --------------------------------------------------------------------------
bool History::processAction(std::ifstream& inputFile, IStore* store)
{
	char action = ' '; 
	string badData;
	int id;
	bool returnValue;

	inputFile >> action;
	inputFile >> id;

	if (store->getCustomerHashTablePtr().retrieve(id) == NULL)
	{
		cout << "Incorrect Customer ID." << endl;
		getline(inputFile, badData); //get the rest of the data of the wrong ID
		returnValue = false;
				
	}
	else if (store->getCustomerHashTablePtr().retrieve(id) != NULL)
	{
		IPerson* historyPerson;
		(historyPerson) = store->getCustomerHashTablePtr().retrieve(id);
		returnValue = true;
		//historyPerson->getDVDHistory;
	}

	return returnValue;
}
