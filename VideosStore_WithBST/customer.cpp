//-----------------------------------------------------------------------------
// File:	customer.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class creates a customer object that inherits from IPerson.
// The customer has attributes such as name and ID for the video store. The customer
// class also holds the customers history of borrowed and return movies. The history
// is pushed into a stack so that everytime the customer borrows or returns a valid
// movie, the movie data is pushed to the stack of history.
//-----------------------------------------------------------------------------

#include "customer.h"
#include <iostream>

using namespace std;


// --------------------------------------------------------------------------
// Function:	Customer::Customer(string firstName, string lastName, int id)
// Title:	Constructor
// Description: Constructs a customer object with a first and last name and 
// store ID.
// Parameters:	string firstName, string lastName, int id
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Customer::Customer(string firstName, string lastName, int id)
{
	//IPerson *new_customer = new IPerson(firstName, lastName, id);
	//IPerson(firstName, lastName, id);
	m_firstName = firstName;
	m_lastName = lastName;
	m_id = id;
	m_hashKey = id;
}

// --------------------------------------------------------------------------
// Function:	Customer::~Customer()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Customer::~Customer()
{
	//while (!m_inventoryLLPtr->isEmpty())
	//{
	//	m_inventoryLLPtr->removeFront();
	//}
}

// --------------------------------------------------------------------------
// Function:	int Customer::getID()
// Title:	get customer id
// Description: get customer id
// Parameters:	N/A
// Returns:	int
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int Customer::getID()
{
	return m_id;
}

// --------------------------------------------------------------------------
// Function:	stack<string> Customer::getDVDHistory()
// Title:	accessor for m_dvdHisory
// Description: checks the stack of the customer's dvd history, and as long as 
// the stack is not empty, it will pop the history of movies if borrowed or returned
// Parameters:	N/A
// Returns:	stack<string>
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
stack<string> Customer::getDVDHistory()
{
	string temp;
	int counter = 1;
	while (!m_dvdHistory.empty())
	{	
		cout << counter << ". " << m_dvdHistory.top();
	    m_dvdHistory.pop();
	    cout << "\n"; // go to next line
		counter++;
	}
	return m_dvdHistory;
}

// --------------------------------------------------------------------------
// Function:	vector<string> Customer::getInventory()
// Title:		accessor for m_inventory
// Description: returns a vector of the DVD items that the customer has borrowed
// Parameters:	N/A
// Returns:		vector<string>
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
vector<string> Customer::getInventory()
{
	return m_inventory;
}

// --------------------------------------------------------------------------
// Function:	void Customer::addInventory(string identifying_property)
// Title:		add item to inventory
// Description: adds a representation of a DVD object to the customer's
//				inventory
// Parameters:	string identifying_property; the string representation
//				of the DVD
// Returns:		void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Customer::addInventory(string identifying_property)
{
	m_inventory.push_back(identifying_property);
}

// --------------------------------------------------------------------------
// Function:	bool Customer::removeInventory(string identifying_property)
// Title:		remove item from inventory
// Description: removes a representation of a DVD object from the customer's
//				inventory
// Parameters:	string identifying_property; the string representation
//				of the DVD
// Returns:		bool; true if removed, false if not
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Customer::removeInventory(string identifying_property)
{
	bool removed = false;
	vector<string>::iterator i = m_inventory.begin();
	{
		while (i != m_inventory.end())
		{
			if (*i == identifying_property)
			{
				m_inventory.erase(i);
				removed = true;
				return removed;
			}
			else
			{
				i++;
			}
		}
	}
}

// ---------------------------- setHistory ----------------------------------
// Function:	void Customer::setHistory(string historyLine)
// Title:	push to the stack of dvd history
// Description: Pushes a borrow or return information into m_dvdHistory which is the stack
// of strings that contains customers history.
// Parameters:  string historyline
// Returns:	stack<string>
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Customer::setHistory(string historyLine)
{
	m_dvdHistory.push(historyLine);
}
