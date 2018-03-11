#include "hash.h"
#include <iostream>

// --------------------------------------------------------------------------
// hash table constructor
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
// destructor
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
	delete hashTable;
}

// --------------------------------------------------------------------------
// insert
// --------------------------------------------------------------------------
bool Hash::insert(Customer* customer)
{	
	//if(person->getHashKey() < TABLE_SIZE && person->getHashKey() > 0)
	if (customer->getHashKey() >= 0)
	{
		int hashVal;
		hashVal = customer->getHashKey() % TABLE_SIZE;
		if (hashTable[hashVal] == NULL)
		{
			hashTable[hashVal] = customer;
		}
		else
		{
			while (hashTable[hashVal] == NULL)
			{
				//increment hashVal++ linear probing have to figure this out---------------
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

// --------------------------------------------------------------------------
// retrieve
// --------------------------------------------------------------------------
IPerson* Hash::retrieve(int key)
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