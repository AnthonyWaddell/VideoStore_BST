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
	bool return_value = false;

	//search store inventory to find movie based on movie type, binary tree
	//change customers history and inventory
	//change stores inventory.

	//inputFile >> action; don't know if we need this, keeping for now in case we do
	inputFile >> id;
	if (store->getCustomerHashTablePtr().retrieve(id) == NULL)
	{
		cout << "Incorrect Customer ID." << endl;
	}

	// Get customer valid account 
	Customer* customerInfo = store->getCustomerHashTablePtr().retrieve(id);

	// Read in media type (in implementation only dvd), and genre
	inputFile >> mediaType;
	inputFile >> genre;

	switch (genre)
	{
	case 'F':
		// Get comedy attributes and return comedy film
		getline(inputFile, movieTitle, ',');
		inputFile >> releaseYear;
		//return_value = store->getComedyTree().returnComedy(movieTitle, releaseYear, store->getComedyTree().getRoot());
		//customerInfo->setHistory(action + " " + id + " D " + "F " + movieTitle + ", " + releaseYear)
		break;
	case 'D':
		// Get drama attributes and return drama film
		getline(inputFile, director, ',');
		getline(inputFile, movieTitle, ',');
	/*	return_value = store->getDramaTree().returnDrama(director, movieTitle, store->getDramaTree().getRoot());
		customerInfo->setHistory(action + " " + id + " D " + "D " + director + ", " + movieTitle + ",")	
		break;*/
	case 'C':
		// Get classical attributes and return drama film
		inputFile >> releaseMonth >> releaseYear >> firstNameMajor >> lastNameMajor;
		//return_value = store->getClassicalTree().returnClassical
		//(releaseMonth, releaseYear, firstNameMajor, lastNameMajor, store->getClassicalTree().getRoot());
		//customerInfo->setHistory(action + " " + id + " D " + "C " + releaseMonth + " " + releaseYear + " " + firstNameMajor + " " + lasNameMajor)
		break;
	default:
		cout << "Invalid Movie Code." << endl;
		break;
	}

	//customer inventory not required to be kept
	return return_value;
}
