#include "customer.h"
#include <iostream>

using namespace std;


// --------------------------------------------------------------------------
// constructor with parameters
// --------------------------------------------------------------------------
Customer::Customer(string firstName, string lastName, int id)
{
	IPerson *new_customer = new IPerson(firstName, lastName, id);

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
	while (!m_dvdHistory.empty())
	{
	    m_dvdHistory.pop();
	    cout << "\n"; // go to next line
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
