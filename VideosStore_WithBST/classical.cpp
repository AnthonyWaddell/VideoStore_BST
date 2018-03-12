//-----------------------------------------------------------------------------
// File:	classical.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class creates an object of a type classical moive by reading
// from the input file of creating a dvd inventory of the store. This is created 
// from the dFactory class. Classical.cpp will read the rest of the line after 
// getting the type of dvd which is C and assign it the correct values. 
//-----------------------------------------------------------------------------


#include "classical.h"

// --------------------------------------------------------------------------
// Function:	Classical::~Classical()
// Title:	Destructor
// Description: Destructor of a classical object
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Classical::~Classical()
{
}

// --------------------------------------------------------------------------
// Function:	void Classical::display()
// Title:	display the movie attributes
// Description: the method uses the iostream to ouput the attributes of the 
//		classical movie
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::display() const
{
	cout << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_majorActorFirstName << " " <<
		m_majorActorLastName << " " << m_monthReleased << " " <<
		m_yearReleased << endl;
}

// --------------------------------------------------------------------------
// Function:	void Classical::genDisplay(string & genDisplayString)
// Title:	display of movie
// Description: displays the entire movie line
// Parameters:	string & genDisplayString
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::genDisplay(string & genDisplayString)
{
	string comma_space = ", ";
	string space = " ";
	genDisplayString += m_genreAbbrev;
	genDisplayString += comma_space;
	genDisplayString += m_stock;
	genDisplayString += comma_space;
	genDisplayString += m_director;
	genDisplayString += comma_space;
	genDisplayString += m_title;
	genDisplayString += comma_space;
	genDisplayString += m_majorActorFirstName;
	genDisplayString += space;
	genDisplayString += m_majorActorLastName;
	genDisplayString += space;
	genDisplayString += m_monthReleased;
	genDisplayString += space;
	genDisplayString += m_yearReleased;
}

// --------------------------------------------------------------------------
// Function:	void Classical::genCopy(IItem * itemPtr)
// Title:	generate a copy of the pointer item
// Description: method creates a copyt of the current movie object.
// Parameters:	IItem * itemPtr
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::genCopy(IItem * itemPtr)
{
	Classical *temp = static_cast<Classical*>(itemPtr);
	if (temp->getGenre() == 'C')
	{
		this->m_stock = temp->m_stock;
		this->m_director = temp->m_director;
		this->m_title = temp->m_title;
		this->m_majorActorFirstName = temp->m_majorActorFirstName;
		this->m_majorActorLastName = temp->m_majorActorLastName;
		this->m_monthReleased = temp->m_monthReleased;
		this->m_yearReleased = temp->m_yearReleased;
	}
}

// --------------------------------------------------------------------------
// Function:	void Classical::buildDVD(char genre, ifstream & inputFileInventory)
// Title:	createa DVD object
// Description: method creates a dvd object of type classical by reading in the rest
// of the input file. this will assign the movie's attributes along with how many in stock
// Parameters:	char genre, ifstream & inputFileInventory
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::buildDVD(char genre, ifstream & inputFileInventory)
{
	// This needs error handling
	string comma = "";

	// C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
	// C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942
	// C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
	this->setGenreAbbrev(genre);
	getline(inputFileInventory, comma, ' ');
	inputFileInventory >> this->m_stock;
	getline(inputFileInventory, comma, ' ');
	getline(inputFileInventory, this->m_director, ',');
	getline(inputFileInventory, this->m_title, ',');
	inputFileInventory >> this->m_majorActorFirstName;
	//maybe a cin.get() or cin.ignore() to eat up the space
	inputFileInventory >> this->m_majorActorLastName;
	//maybe a cin.get() or cin.ignore() to eat up the space
	inputFileInventory >> this->m_monthReleased;
	inputFileInventory >> this->m_yearReleased;
}

// --------------------------------------------------------------------------
// Function:	bool Classical::operator==(IItem * itemPtr)
// Title:	compare different classical movies
// Description: compare classical movies 
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Classical::operator==(IItem * itemPtr)
{
	bool equal = false;
	Classical *temp = static_cast<Classical*>(itemPtr);
	if (this->getMonthReleased() == temp->getMonthReleased() && 
		this->getYearReleased() == temp->getYearReleased() &&
		this->getMajorActorFirstName() == temp->getMajorActorFirstName() &&
		this->getMajorActorLastName() == temp->getMajorActorLastName())
	{
		equal = true;
	}
	return equal;
}

// --------------------------------------------------------------------------
// Function:	bool Classical::operator<(IItem * itemPtr)
// Title:	compare classical movies
// Description: compare classical movies by relase date and major actor 
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Classical::operator<(IItem * itemPtr)
{
	bool return_value = false;
	Classical *temp = static_cast<Classical*>(itemPtr);

	if (this->getYearReleased() < temp->getYearReleased())
	{
		return_value = true;
	}
	// If both items came out in the same year
	else if (this->getYearReleased() == temp->getYearReleased())
	{
		if (this->getMonthReleased() < temp->getMonthReleased())
		{
			return_value = true;
		}
		else if (this->getMonthReleased() == temp->getMonthReleased())
		{
			if (this->getMajorActorLastName() < temp->getMajorActorLastName())
			{
				return_value = true;
			}
			else if (this->getMajorActorLastName() == temp->getMajorActorLastName())
			{
				if (this->getMajorActorFirstName() < temp->getMajorActorFirstName())
				{
					return_value = true;
				}
			}
		}
	}
	
	return return_value;
}

// --------------------------------------------------------------------------
// Function:	bool Classical::operator>(IItem * itemPtr)
// Title:	compare classical movies
// Description: compare classical movies by relase date and major actor 
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Classical::operator>(IItem * itemPtr)
{
	bool return_value = false;
	Classical *temp = static_cast<Classical*>(itemPtr);

	if (this->getYearReleased() > temp->getYearReleased())
	{
		return_value = true;
	}
	// If both items came out in the same year
	else if (this->getYearReleased() == temp->getYearReleased())
	{
		if (this->getMonthReleased() > temp->getMonthReleased())
		{
			return_value = true;
		}
		else if (this->getMonthReleased() == temp->getMonthReleased())
		{
			if (this->getMajorActorLastName() > temp->getMajorActorLastName())
			{
				return_value = true;
			}
			else if (this->getMajorActorLastName() == temp->getMajorActorLastName())
			{
				if (this->getMajorActorFirstName() > temp->getMajorActorFirstName())
				{
					return_value = true;
				}
			}
		}
	}

	return return_value;
}

// --------------------------------------------------------------------------
// Function:	int Classical::getMonthReleased()
// Title:	Accessor for month release date
// Description: Return the month the movie was released.
// Parameters:	N/a
// Returns:	int
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int Classical::getMonthReleased()
{
	return m_monthReleased;
}

// --------------------------------------------------------------------------
// Function:	string Classical::getMajorActorFirstName()
// Title:	Accessor for major actor first name
// Description: Return the string of the first name of major actor
// Parameters:	N/A
// Returns:	string
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
string Classical::getMajorActorFirstName()
{
	return m_majorActorFirstName;
}

// --------------------------------------------------------------------------
// Function:	string Classical::getMajorActorLastName()
// Title:	Accessor for major actor last name
// Description: Return the string of the last name of major actor
// Parameters:	N/A
// Returns:	string
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
string Classical::getMajorActorLastName()
{
	return m_majorActorLastName;
}

// --------------------------------------------------------------------------
// Function:	void Classical::setMonthReleased(int month)
// Title:	Mutator for release month
// Description: sets the month for the movie
// Parameters:	int month
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::setMonthReleased(int month)
{
	int january = 1;
	int december = 12;

	if (month >= january && month <= december)
	{
		m_monthReleased = month;
	}
}

// --------------------------------------------------------------------------
// Function:	void Classical::setMajorActorFirstName(string firstName)
// Title:	Mutator for major actor first name
// Description: sets the first name of the major actor
// Parameters:	string firstName
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::setMajorActorFirstName(string firstName)
{
	m_majorActorFirstName = firstName;
}

// --------------------------------------------------------------------------
// Function:	void Classical::setMajorActorLastName(string lastName)
// Title:	Mutator for major actor last name
// Description: sets the last name of the major actor
// Parameters:	string lastName
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Classical::setMajorActorLastName(string lastName)
{
	m_majorActorLastName = lastName;
}

