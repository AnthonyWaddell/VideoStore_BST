#include "originalstore.h"
#include <string.h>

using namespace std;
// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
OriginalStore::~OriginalStore()
{
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::buildStore(std::ifstream & inputFileCustomers, std::ifstream & inputFileInventory)
{
	buildInventory(inputFileInventory);
	buildCustomers(inputFileCustomers);
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::runStore(std::ifstream & inputFileCommands)
{
	IAction *action_ptr = NULL;
	char typeOfAction = ' ';
	string invalidAction = "";
	IStore *newStore = new OriginalStore();

	while (true)
	{
		if (inputFileCommands.eof())
		{
			break;
		}
		inputFileCommands >> typeOfAction;

		action_ptr = AFactory::createAction(typeOfAction);
		if (action_ptr == NULL)
		{
			cout << "Invalid Action" << endl;
			getline(inputFileCommands, invalidAction);
			continue;
		}
		else
		{
			action_ptr->processAction(inputFileCommands, newStore);
		}

	}
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::buildCustomers(std::ifstream & inputFileCustomers)
{
	while (true)
	{
		if (inputFileCustomers.eof())
		{
			break;
		}

		int id;
		string first_name;
		string last_name;

		inputFileCustomers >> id;
		getline(inputFileCustomers, last_name, ' ');
		getline(inputFileCustomers, first_name, ' ');
		IPerson *newCustomer = new Customer(first_name, last_name, id);
		m_customerHashPtr->insert(newCustomer);
	}
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::buildInventory(std::ifstream & inputFileInventory)
{
	DVD *dvd_ptr = NULL;
	char genre = ' ';
	string bad_data = "";
	bool duplicate = false;

	while (true)
	{
		if (inputFileInventory.eof())
		{
			break;
		}
		inputFileInventory >> genre;
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
