//-----------------------------------------------------------------------------
// File:	return.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class is based off an action from the command file.
// The processAction method sets the history to the  customer doing the 
// returning of the dvd. It makes validation checks to see that the
// chars in a certain place are correct identifies.
//----------------------------------------------------------------------

#include "return.h"
#include <iostream>
#include "originalstore.h"
#include "istore.h"
#include "hash.h"
#include "iperson.h"
#include "customer.h"

using namespace std;


// ---------------------------- ~Return -------------------------------------
// Function:	Return::~Return()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Return::~Return()
{

}

// ---------------------------- processAction -------------------------------
// Function:	bool Return::processAction(std::ifstream& inputFile, IStore* store)
// Title:	process the return action
// Description: rocesses the return action reading what to do from a input file.
// Preconditions: A valid IStore object. Correctly formatted input file line.
// Postconditions: Input file ifstream will be at the end of the line. IStore
// will have added movie to its inventory and removed from the customer's
// inventory if a valid movie and valid customer; otherwise, error message
// is printed to screen. Also, the return, if valid, will be added to
// customer's history.
// Parameters:	inputFile - A input file with lines of properly formatted commands.
// Returns:	Returns true if return was successful, and false otherwise.
// History Log: 03/14/18 AW Completed Function 
// --------------------------------------------------------------------------
bool Return::processAction(std::ifstream& inputFile, IStore* store)
{
	string action = "R";
	int id;
	char mediaType = ' ';
	char genre = ' ';
	string badData;
	string movieTitle;
	string director;
	string firstNameMajor;
	string lastNameMajor;
	string s_id;
	string s_releaseMonth;
	string s_releaseYear;
	int release_year;
	int release_month;
	int key;
	bool return_value = false;

	inputFile >> id;
	key = store->getCustomerHashTablePtr().generateHashKey(id);
	s_id = to_string(id);
	if (store->getCustomerHashTablePtr().retrieve(key) == NULL)
	{
		getline(inputFile, badData);
		cout << "Incorrect Customer ID." << endl;
	}

	// Get customer valid account 
	Customer* customerInfo = store->getCustomerHashTablePtr().retrieve(key);

	// Read in media type (in implementation only dvd), and genre
	inputFile >> mediaType;
	inputFile >> genre;

	switch (genre)
	{
	case 'F':
		// Get comedy attributes and return comedy film
		getline(inputFile, movieTitle, ',');
		//Check to see that customer had borrowed DVD before returning
		if (customerInfo->removeInventory(movieTitle))
		{
			inputFile >> s_releaseYear;
			release_year = stoi(s_releaseYear);
			return_value = store->getComedyTree().returnComedy(movieTitle, release_year, store->getComedyTree().getRoot());
			customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + movieTitle + ", " + s_releaseYear);
		}
		// If customer never borrowed DVD
		else
		{
			cout << "Customer does not a copy of that film to return" << endl;
		}
		break;
	case 'D':
		// Get drama attributes and return drama film
		getline(inputFile, director, ',');
		getline(inputFile, movieTitle, ',');
		//Check to see that customer had borrowed DVD before returning
		if (customerInfo->removeInventory(movieTitle))
		{
			return_value = store->getDramaTree().returnDrama(director, movieTitle, store->getDramaTree().getRoot());
			customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + director + ", " + movieTitle);
		}
		// If customer never borrowed DVD
		else
		{
			cout << "Customer does not a copy of that film to return" << endl;
		}
		break;
	case 'C':
		// Get classical attributes and return drama film
		inputFile >> s_releaseMonth >> s_releaseYear >> firstNameMajor >> lastNameMajor;
		release_year = stoi(s_releaseYear);
		release_month = stoi(s_releaseMonth);
		//Check to see that customer had borrowed DVD before returning
		if (customerInfo->removeInventory(s_releaseMonth += firstNameMajor))
		{
			return_value = store->getClassicalTree().returnClassical
			(release_month, release_year, firstNameMajor, lastNameMajor, store->getClassicalTree().getRoot());
			customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + s_releaseMonth + " " + s_releaseYear + " " + firstNameMajor + " " + lastNameMajor);
		}
		// If customer never borrowed DVD
		else
		{
			cout << "Customer does not a copy of that film to return" << endl;
		}
		break;
		// If invalid command
	default:
		cout << "Invalid media type or genre: " << "media type: " << mediaType << " " << "genre: " << genre << endl;
		getline(inputFile, badData);
		break;
	}
	return return_value;
}
