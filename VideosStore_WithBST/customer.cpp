#include "customer.h"
#include <iostream>

using namespace std;


// --------------------------------------------------------------------------
// constructor with parameters
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
// destructor
// --------------------------------------------------------------------------
Customer::~Customer()
{
	//while (!m_inventoryLLPtr->isEmpty())
	//{
	//	m_inventoryLLPtr->removeFront();
	//}
}

// --------------------------------------------------------------------------
// accessor for m_dvdHistory
// --------------------------------------------------------------------------
stack<string> Customer::getDVDHistory()
{
	int counter = 1;
	while (!m_dvdHistory.empty())
	{	
		cout << counter << ". ";
	    m_dvdHistory.pop();
	    cout << "\n"; // go to next line
		counter++;
	}
	return m_dvdHistory;
}
//
//// --------------------------------------------------------------------------
//// accessor for m_inventoryLLPtr
//// --------------------------------------------------------------------------
//LinkedList * Customer::getInventoryLLPtr()
//{
//	return m_inventoryLLPtr;
//}

// ---------------------------- setHistory ----------------------------------
// Pushes a borrow or return information into m_dvdHistory which is the stack
// of strings that contains customers history.
// Preconditions: None.
// Postconditions: m_dvdHistory contains newly added history line that is
// a borrow or a return with the information.
// --------------------------------------------------------------------------
void Customer::setHistory(string historyLine)
{
	m_dvdHistory.push(historyLine);
}
