#include "history.h"
#include <iostream>

using namespace std;



// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
History::~History()
{



}

bool History::processAction(std::ifstream& inputFile, IStore* store)
{
	char action = ' '; // not sure if needed 
	string badData;
	int id;
	bool returnValue;

	inputFile >> action;
	inputFile >> id;

	if (store->getCustomerHashTablePtr()->retrieve(id) == NULL)
	{
		cout << "Incorrect Customer ID." << endl;
		getline(inputFile, badData); //get the rest of the data of the wrong ID
		returnValue = false;
		
		
	}
	else if (store->getCustomerHashTablePtr()->retrieve(id) != NULL)
	{
		IPerson* historyPerson;
		static_cast<Customer*>(historyPerson) = store->getCustomerHashTablePtr()->retrieve(id);
		//historyPerson check its history
	}



	return returnValue;


}
