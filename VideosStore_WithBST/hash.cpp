//-----------------------------------------------------------------------------
// File:	hash.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class is a hashtable that holds customer's ID for when reting 
// a dvd. A hash table is created to hold the customer's data. The size of the hash table
// is size 2003. We wanted 2000 places with 2003 being the next prime number.
//-----------------------------------------------------------------------------

#include "hash.h"
#include <iostream>

// --------------------------------------------------------------------------
// Function:	Hash::Hash()
// Title:	Constructor
// Description: Create an array size of 2003 and insert NULL into all of them
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Hash::Hash()
{
	//m_hashTable = new IPerson*[TABLE_SIZE];

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

// --------------------------------------------------------------------------
// Function:	Hash:~:Hash()
// Title:	Destructor
// Description: Delete each index hold an object and assigning it a NULL value
// and then deleteing the entire hashtable.
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Hash::~Hash()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i] != NULL)
		{
			// Think this is gonna cause a memory leak
			delete hashTable[i];
			hashTable[i] = NULL;
		}
	}
	delete[] hashTable;
}

// --------------------------------------------------------------------------
// Function:	int Hash::generateHashKey(int id) const
// Title:	generate a hashkey
// Description: method takes in the customer's id and then creates the hashkey
// in order to access the customer in the hashtable.
// Parameters:	int id
// Returns:	int
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int Hash::generateHashKey(int id) const
{
	int key = id % TABLE_SIZE;
	return key;
}

// --------------------------------------------------------------------------
// Function:	bool Hash::insert(Customer* customer)
// Title:	insert customer to hashtable
// Description: method takes in a customer object and then gets its hashkey
// and checks that that hashkey in the table is NULL to be able to insert. It will
// go to the nxt available index if the current one is not NULL.
// Parameters:	customer* customer
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Hash::insert(Customer* customer)
{	
	//check that hashkey is not negative
	if (customer->getHashKey() >= 0)
	{
		//create hashkey
		int hashVal = generateHashKey(customer->getID());
		if (hashTable[hashVal] == NULL)
		{
			hashTable[hashVal] = customer;
			customer->setHashKey(hashVal);
		}
		else
		{
			//loop until the index in the hashtable is empty to insert
			while (hashTable[hashVal] == NULL)
			{
				hashVal++;
			}
			hashTable[hashVal] = customer;
			customer->setHashKey(hashVal);
		}
		return true;
	}
	else
	{
		return false;
	}
}

// --------------------------------------------------------------------------
// Function:	Customer* Hash::retrieve(int key)
// Title:	retrieve customer
// Description: takes in the key of a customer and checks the hashtable in that
// index to return the customer. If the key access an empty index then return false
// Parameters:	int key
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Customer* Hash::retrieve(int key) const
{
	if (hashTable[key] == NULL)
	{
		return NULL;
	}
	else
	{
		return hashTable[key];
	}
}
