//-----------------------------------------------------------------------------
// File:	dvd.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class is a parent class of type of dvds. It inherits from 
// item. The DVD has a genre type and director. Classes drama, comedy, and 
// classical inherit from DVD class
//-----------------------------------------------------------------------------

#include "dvd.h"

// --------------------------------------------------------------------------
// Function:	DVD::DVD()
// Title:	Constructor
// Description: Constructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
DVD::DVD()
{
}

// --------------------------------------------------------------------------
// Function:	DVD::~DVD()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
DVD::~DVD()
{
}

// --------------------------------------------------------------------------
// Function:	char DVD::getGenre()
// Title:	Accessor of genre
// Description: gets the genre type
// Parameters:	N/A
// Returns:	char
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
char DVD::getGenre()
{
	return m_genreAbbrev;
}

// --------------------------------------------------------------------------
// Function:	string DVD::getDirector()
// Title:	accessor for m_director;
// Description: gets the director name
// Parameters:	N/A
// Returns:	string
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
string DVD::getDirector()
{
	return m_director;
}

// --------------------------------------------------------------------------
// Function:	void DVD::setDirector(string director)
// Title:	mutator for m_director
// Description: sets the director name
// Parameters:	string director
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void DVD::setDirector(string director)
{
	m_director = director;
}

// --------------------------------------------------------------------------
// Function:	void DVD::setGenreAbbrev(char genreAbbrev)
// Title:	mutator for m_genreAbbrev
// Description: sets the genre
// Parameters:	char genreAbbrev
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void DVD::setGenreAbbrev(char genreAbbrev)
{
	//Not sure if we should error check this to only allow  F D and/or C
	m_genreAbbrev = genreAbbrev;
}

// --------------------------------------------------------------------------
// compares by genre for sorting/inserting purposes
// Function:	int DVD::compareByGenre(char genre)
// Title:	compares by genre for sorting/inserting purposes
// Description: compare dvd genre and return 0 when match is found
// Parameters:	char genre
// Returns:	int
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int DVD::compareByGenre(char genre)
{
	int return_value;

	switch (toupper(this->m_genreAbbrev))
	{
	case 'F':
		if (genre == 'F')
			return_value = 0;
		if (genre == 'D')
			return_value = 1;
		if (genre == 'C')
			return_value = 1;
		break;
	case 'D':
		if (genre == 'F')
			return_value = -1;
		if (genre == 'D')
			return_value = 0;
		if (genre == 'C')
			return_value = 1;
		break;
	case 'C':
		if (genre == 'F')
			return_value = -1;
		if (genre == 'D')
			return_value = -1;
		if (genre == 'C')
			return_value = 0;
		break;
	default:
		cout << "Invalid genre" << endl;
	}
	return return_value;
}

