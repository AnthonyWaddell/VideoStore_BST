//-----------------------------------------------------------------------------
// File:	afactory.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class is a design pattern of a factory that creates a dvd
// movie type. The factory uses a switch statement and creates the type of movie
// object depending on the char in the input line that represents the genre of the movie
//-----------------------------------------------------------------------------

#include "dfactory.h"
#include <iostream>
using namespace std;

// --------------------------------------------------------------------------
// Function:	DFactory::~DFactory()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
DFactory::~DFactory()
{
}

// --------------------------------------------------------------------------
// return pointer to dvd type
// Function:	DVD * DFactory::createDVD(char genre)
// Title:	factory builder of movie types
// Description: the factory creates a movie type using a switch statement that 
// reads a char from the input file of creating a dvd inventory. 
// Parameters:  char genre
// Returns:	DVD 
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
DVD * DFactory::createDVD(char genre)
{
	DVD *m_dvd = NULL;
	genre = toupper(genre);

	switch (genre)
	{
	case 'F':
		m_dvd = new Comedy();
		break;
	case 'D':
		m_dvd = new Drama();
		break;
	case 'C':
		m_dvd = new Classical();
		break;
	default:
		cout << "Incompatible genre" << endl;
		break;
	}
	return m_dvd;
}
