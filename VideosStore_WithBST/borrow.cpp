//-----------------------------------------------------------------------------
// File:	borrow.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class is used to check the inventory of the store and adds 
// to the customer's history the movie that it will borrow. It will read from 
// the command file by reading each word separated by a space. The checks will
// be to make sure the customer ID is valid in the hashtable, check that the 
// item type is D, movie type is valid, and title to be valid. If all these are not valid
// then the movie is not added to the cutomer's history.
//-----------------------------------------------------------------------------

#include <iostream>
#include "borrow.h"
#include "originalstore.h"
#include "istore.h"
#include "hash.h"
#include "iperson.h"
#include "customer.h"

using namespace std;

// ---------------------------- ~Borrow -------------------------------------
// Function:	Borrow::~Borrow())
// Title:	Destructor
// Description: Destructor for borrowed movies
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Borrow::~Borrow()
{

}

// ---------------------------- processAction -------------------------------
// Function: bool Borrow::processAction(std::ifstream& inputFile, IStore* store)
// Title:  Processes the borrow action reading what to do from a input file.
// Description: A valid IStore object. Correctly formatted input file line.
// Input file ifstream will be at the end of the line. IStore
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
	int id; // customer id
	int key; // hashtable key
	string action = "B"; //action to be done
	char mediaType = ' '; //D for DVD, anything else is invalid
	char genre = ' '; //type of DVD
	string badData; //take in rest of line if above values are invalid
	string movieTitle;
	string director;
	string firstNameMajor; //major actor or actress first name
	string lastNameMajor; //major actor or actress las name
	string s_releaseMonth; //classical movie release month
	string s_releaseYear; //movie release year
	int release_year; 
	int release_month;
	bool return_value = false;//checks if the entire command is valid
	bool contains = false;

	//search store inventory to find movie based on movie type, binary tree
	//change customers history and inventory
	//change stores inventory.

	
		//inputFile >> action;
		inputFile >> id;
		string s_id = to_string(id);
		key = store->getCustomerHashTablePtr().generateHashKey(id);
		if (store->getCustomerHashTablePtr().retrieve(key) == NULL)
		{
			cout << "Incorrect Customer ID: " << id << endl;
			getline(inputFile, badData); //get the rest of the  data of the wrong ID
			return_value = false;
		} 
		else
		{
			//get customer valid account 
			Customer* customerInfo = store->getCustomerHashTablePtr().retrieve(key);
			inputFile >> mediaType;
			inputFile >> genre;

			if (genre == 'F' && mediaType == 'D')
			{
				getline(inputFile, movieTitle, ',');
				contains = store->getComedyTree().contains(movieTitle);
				if (!contains)
				{
					return return_value;
				}
				//search inventory of store if not found then break
				inputFile >> s_releaseYear;
				release_year = stoi(s_releaseYear);
				return_value = store->getComedyTree().borrowComedy(movieTitle, release_year, store->getComedyTree().getRoot());
				customerInfo->setHistory(action + " " + s_id + " " + mediaType +  " " + genre + " " + movieTitle + ", " + s_releaseYear);
			}
			else if (genre == 'D' && mediaType == 'D')
			{
				getline(inputFile, director, ',');
				//search inventory of store if not found then break
				getline(inputFile, movieTitle, ',');
				contains = store->getComedyTree().contains(movieTitle);
				if (!contains)
				{
					return return_value;
				}
				return_value = store->getDramaTree().borrowDrama(director, movieTitle, store->getDramaTree().getRoot());
				customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + director + ", " + movieTitle + ",");
			}
			else if (genre == 'C' && mediaType == 'D')
			{
				inputFile >> s_releaseMonth;
				inputFile >> s_releaseYear;
				inputFile >> firstNameMajor;
				inputFile >> lastNameMajor;
				release_month = stoi(s_releaseMonth);
				release_year = stoi(s_releaseYear);
				return_value = store->getClassicalTree().borrowClassical
				(release_month, release_year, firstNameMajor, lastNameMajor, store->getClassicalTree().getRoot());
				//search inventory of store if not found
				customerInfo->setHistory(action + " " + s_id + " " + mediaType + " " + genre + " " + s_releaseMonth + " " + s_releaseYear + " " + firstNameMajor + " " + lastNameMajor);
			}
			else
			{
				cout << "Invalid media type or genre: " << "media type: " << mediaType << " " << "genre: " << genre << endl;
				getline(inputFile, badData);
				return_value = false;

			}
		}
	return return_value;
}
