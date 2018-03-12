//-----------------------------------------------------------------------------
// File:	iperson.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The iperson class is a base class that can be extended to be any 
// sort of person. The iperson is the base class for our customer class that is 
// a person. Iperson can hold a name and a hashkey to be ineserted in a hashtable.
//-----------------------------------------------------------------------------

#include "iperson.h"

//--------------------------------------------------------------------------
// Function:	IPerson::IPerson()
// Title:	Contructor
// Description: Contructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IPerson::IPerson()
{
}

// --------------------------------------------------------------------------
// Function:	IPerson::IPerson()
// Title:	constructor with parameters
// Description: Contructor that takes in a first and last name along with a hashkey
// Parameters:	string firstName, string lastName, int hashKey
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IPerson::IPerson(string firstName, string lastName, int hashKey)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_hashKey = hashKey;
}

// --------------------------------------------------------------------------
// Function:	IPerson::~Person()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IPerson::~IPerson()
{
}

// --------------------------------------------------------------------------
// Function:	int IPerson::getHashKey()
// Title:	accessor for m_hashKey
// Description: get the hashkey
// Parameters:	N/A
// Returns:	int
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int IPerson::getHashKey()
{
	return m_hashKey;
}

// --------------------------------------------------------------------------
// Function:	void IPerson::setHashKey(int key)
// Title:	mutator for m_hashKey
// Description: set the hashkey of a person
// Parameters:	int key
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void IPerson::setHashKey(int key)
{
	if (key >= 0 && key <= 2003)
	{
		m_hashKey = key;
	}
}

// --------------------------------------------------------------------------
// Function:	string IPerson::getFirstName()
// Title:	accessor for m_firstName
// Description: get the first name of an iperson
// Parameters:	N/A
// Returns:	string
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
string IPerson::getFirstName()
{
	return m_firstName;
}

// --------------------------------------------------------------------------
// 
// Function:	string IPerson::getLastName()
// Title:	accessor for m_lastName
// Description: get the last name of an iperson
// Parameters:	N/A
// Returns:	string
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
string IPerson::getLastName()
{
	return m_lastName;
}
