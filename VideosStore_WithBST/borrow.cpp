#include <iostream>
#include "borrow.h"
#include "originalstore.h"
#include "istore.h"
#include "hash.h"
#include "iperson.h"
#include "customer.h"

using namespace std;


// ---------------------------- ~Borrow -------------------------------------
// An empty virtual destructor for extensibility.
// Preconditions: None.
// Postconditions: None.
// --------------------------------------------------------------------------
Borrow::~Borrow()
{

}

// ---------------------------- processAction -------------------------------
// Processes the borrow action reading what to do from a input file.
// Preconditions: A valid IStore object. Correctly formatted input file line.
// Postconditions: Input file ifstream will be at the end of the line. IStore
// will have removed movie from its inventory and added to the customer's
// inventory if a valid movie and valid customer; otherwise, error message
// is printed to screen. Also, the borrow, if valid, will be added to
// customer's history.
// Parameter: inputFile - A input file with lines of properly formatted
// commands.
// store - An IStore object.
// Return: Returns true if borrow was successful, and false otherwise.
// --------------------------------------------------------------------------
bool Borrow::processAction(std::ifstream& inputFile, IStore* store)
{
	int id;
	char action = ' ';
	char mediaType = ' ';
	char genre = ' ';
	string badData;
	string movieTitle;
	string director;
	string firstNameMajor;
	string lastNameMajor;
	string releaseMonth;
	string releaseYear;
	bool returnValue;

	//search store inventory to find movie based on movie type, binary tree
	//change customers history and inventory
	//change stores inventory.

	
		inputFile >> action;
		inputFile >> id;
		string s_id = to_string(id);
		
		if (store->getCustomerHashTablePtr().retrieve(id) == NULL)
		{
			cout << "Incorrect Customer ID." << endl;
			getline(inputFile, badData); //get the rest of the  data of the wrong ID
			returnValue = false;
		} 
		else
		{
			//get customer valid account 
			Customer* customerInfo = store->getCustomerHashTablePtr().retrieve(id);

			inputFile >> mediaType; //no need to handle mediaType if its not D

			inputFile >> genre;
			if (genre != 'F' || genre != 'D' || genre != 'C')
			{
				cout << "Invalid Movie Code." << endl;
				returnValue = false;
			
			}
			else if (genre == 'F')
			{
				getline(inputFile, movieTitle, ',');
				//search inventory of store if not found then break
				inputFile >> releaseYear;
				returnValue = true;
				customerInfo->setHistory(action + " " + s_id + " " + mediaType + genre + movieTitle + ", " + releaseYear);
			}
			else if (genre == 'D')
			{
				getline(inputFile, director, ',');
				//search inventory of store if not found then break
				getline(inputFile, movieTitle, ',');
				returnValue = true;
				customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + director + ", " + movieTitle + ",");
			}
			else if (genre == 'C')
			{
				inputFile >> releaseMonth;
				inputFile >> releaseYear;
				inputFile >> firstNameMajor;
				inputFile >> lastNameMajor;
				returnValue = true;
				//search inventory of store if not found
				customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + releaseMonth + " " + releaseYear + " " + firstNameMajor + " " + lastNameMajor);
			}
		}
	return returnValue; 
}