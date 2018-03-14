//-----------------------------------------------------------------------------
// File:	originalstore.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class creates the actual store that we will use to hold the
// video store library. The class can buildStore by reading from a file with a
// set data. The class builds the customers table, the inventory and reads
// the commands from the file. This class reads all 3 files to make the store run.
//-----------------------------------------------------------------------------


#include "originalstore.h"
#include <string.h>

using namespace std;
// --------------------------------------------------------------------------
// Function:	OriginalStore::~OriginalStore()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
OriginalStore::~OriginalStore()
{
}

void OriginalStore::makeEmpty() 
{
	comedyTree.makeEmpty();
	dramaTree.makeEmpty();
	classicalTree.makeEmpty();
	m_customerHashPtr.makeEmpty();
}

// --------------------------------------------------------------------------
// Function:	void OriginalStore::buildStore(std::ifstream & inputFileCustomers, std::ifstream & inputFileInventory)
// Title:	build the store database
// Description: reads all 3 files to build inventory and run commands.
// Parameters:	std::ifstream & inputFileCustomers, std::ifstream & inputFileInventory
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void OriginalStore::buildStore(std::ifstream & inputFileCustomers, std::ifstream & inputFileInventory)
{
	buildInventory(inputFileInventory);
	buildCustomers(inputFileCustomers);
}

// --------------------------------------------------------------------------
// Function:	void OriginalStore::runStore(std::ifstream & inputFileCommands)
// Title:	run the store
// Description: runs the store by reading the commands of all the customers who
// borrow and return dvd types
// Parameters:	std::ifstream & inputFileCommands
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void OriginalStore::runStore(std::ifstream & inputFileCommands)
{
	IAction *action_ptr = NULL;
	char typeOfAction = ' ';
	string invalidAction = "";

	while (inputFileCommands >> typeOfAction)
	{
		if (inputFileCommands.eof())
		{
			break;
		}
		/*inputFileCommands >> typeOfAction;*/

		action_ptr = AFactory::createAction(typeOfAction);
		if (action_ptr == NULL)
		{
			//cout << "Invalid Action" << endl;
			getline(inputFileCommands, invalidAction);
			continue;
		}
		else
		{	// Probaby want to delete this pointer after every iteration
			action_ptr->processAction(inputFileCommands, this);
			delete action_ptr;
			action_ptr = NULL;
		}
	}
}

// --------------------------------------------------------------------------
// Function:	void OriginalStore::buildCustomers(std::ifstream & inputFileCustomers)
// Title:	build the customer database
// Description: builds the customers using their ID and adding their info
// into a hashtable of size 2003.
// Parameters:	std::ifstream & inputFileCustomers
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void OriginalStore::buildCustomers(std::ifstream & inputFileCustomers)
{
	int id;
	string first_name;
	string last_name;

	// For some reason it was reading last customer (donald duck) twice? changed to read in this way to break at end of file
	while (inputFileCustomers >> id >> last_name >> first_name)
	{
		Customer *newCustomer = new Customer(first_name, last_name, id);
		m_customerHashPtr.insert(newCustomer);
	}
}

// --------------------------------------------------------------------------
// Function:	void OriginalStore::buildInventory(std::ifstream & inputFileInventory)
// Title:	build store inventory
// Description: builds the store's inventory by reading from the inputFile
// Parameters:	std::ifstream & inputFileInventory. It uses a factory when
// reading the file to see what kind of DVD it is.
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void OriginalStore::buildInventory(std::ifstream & inputFileInventory)
{
	DVD *dvd_ptr = NULL;
	char genre = ' ';
	string bad_data = "";
	bool duplicate = false;

	while (inputFileInventory >> genre)
	{
		if (inputFileInventory.eof())
		{
			break;
		}
		/*inputFileInventory >> genre;*/
		dvd_ptr = DFactory::createDVD(genre);
		if (dvd_ptr == NULL)
		{
			cout << "Invalid data" << endl;
			getline(inputFileInventory, bad_data);
			continue;
		}
		else
		{
			dvd_ptr->buildDVD(genre, inputFileInventory);
			switch (genre)
			{
			case 'F':
				comedyTree.insertComedy(comedyTree.getRoot(), dvd_ptr);
				break;
			case 'D':
				dramaTree.insertDrama(dramaTree.getRoot(), dvd_ptr);
				break;
			case 'C':
				classicalTree.insertClassical(classicalTree.getRoot(), dvd_ptr);
					break;
			default:
				cout << "Invalid genre " << endl;
				break;
			}
		}
	}
}
