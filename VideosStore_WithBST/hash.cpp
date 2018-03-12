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
}

// --------------------------------------------------------------------------
// 
// --------------------------------------------------------------------------
int Hash::generateHashKey(int id) const
{
	int key = id % TABLE_SIZE;
	return key;
}

// --------------------------------------------------------------------------
// insert
// --------------------------------------------------------------------------
bool Hash::insert(Customer* customer)
{	
	if (customer->getHashKey() >= 0)
	{
		int hashVal = generateHashKey(customer->getID());
		if (hashTable[hashVal] == NULL)
		{
			hashTable[hashVal] = customer;
			customer->setHashKey(hashVal);
		}
		else
		{
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
// retrieve
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