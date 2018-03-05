#include "return.h"
#include <iostream>
#include "originalstore.h"
#include "istore.h"
#include "hash.h"
#include "iperson.h"
#include "customer.h"

using namespace std;


// ---------------------------- ~Return -------------------------------------
// An empty virtual destructor for extensibility.
// Preconditions: None.
// Postconditions: None.
// --------------------------------------------------------------------------
Return::~Return()
{

}

// ---------------------------- processAction -------------------------------
// Processes the return action reading what to do from a input file.
// Preconditions: A valid IStore object. Correctly formatted input file line.
// Postconditions: Input file ifstream will be at the end of the line. IStore
// will have added movie to its inventory and removed from the customer's
// inventory if a valid movie and valid customer; otherwise, error message
// is printed to screen. Also, the return, if valid, will be added to
// customer's history.
// Parameter: inputFile - A input file with lines of properly formatted
// commands.
// store - An IStore object.
// Return: Returns true if return was successful, and false otherwise.
// --------------------------------------------------------------------------
bool Return::processAction(std::ifstream& inputFile, IStore* store)
{
	char action = ' ';
	int id;
	char mediaType = ' ';
	char genre = ' ';
	string movieTitle;
	string director;
	string firstNameMajor;
	string lastNameMajor;
	int releaseMonth;
	int releaseYear;


	//search store inventory to find movie based on movie type, binary tree
	//change customers history and inventory
	//change stores inventory.

	while (true)
	{
		inputFile >> action;
		inputFile >> id;

		if (store->getCustomerHashTablePtr->retrieve(id) == NULL)
		{
			cout << "Incorrect Customer ID." << endl;
			break;
		}

		//get customer valid account 
		Customer* customerInfo = store->getCustomerHashTablePtr->retrieve(id);

		inputFile >> mediaType; //no need to handle mediaType if its not D

		inputFile >> genre;
		if (genre != 'F' || genre != 'D' || genre != 'C')
		{
			cout << "Invalid Movie Code." << endl;
			break;
		}
		else if (genre == 'F')
		{
			getline(inputFile, movieTitle, ',');
			//search inventory of store if not found then break
			inputFile >> releaseYear;

			//if movie in inventory cotinue
		}
		else if (genre == 'D')
		{
			getline(inputFile, director, ',');
			//search inventory of store if not found then break
			getline(inputFile, movieTitle, ',');
		}
		else if (genre == 'C')
		{
			inputFile >> releaseMonth;
			inputFile >> releaseYear;
			inputFile >> firstNameMajor;
			inputFile >> lastNameMajor;
			//search inventory of store if not found then break
		}

		break;
	}


	//customer setHistory of actions since all parameters were met
	//customerInfo->setHistory();

	//customer dvd inventory
}
