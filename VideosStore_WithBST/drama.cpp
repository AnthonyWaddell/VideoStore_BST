//-----------------------------------------------------------------------------
// File:	drama.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class creates a DVD of movie type drama. It reads the rest of 
// the line from the input file once it has been identified as a type drama. Other
// functions are used such as displaying the all the attributes of the build dvd
//-----------------------------------------------------------------------------

#include "drama.h"

// --------------------------------------------------------------------------
// Function:	Drama::~Drama()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Drama::~Drama()
{
}

// --------------------------------------------------------------------------
// Function:	void Drama::display()
// Title:	Display the dvd
// Description: print out the attributes of the movie
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Drama::display() const
{
	cout << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_yearReleased << endl;
}

// --------------------------------------------------------------------------
//	create string with relevant properties of this dvd
// Function:	void Drama::genDisplay(string & genDisplayString)
// Title:	relevant properties of dvd
// Description: 
// Parameters:	string & genDisplayString
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Drama::genDisplay(string & genDisplayString)
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
	genDisplayString += m_yearReleased;
}

// --------------------------------------------------------------------------
// Function:	void Drama::genCopy(IItem * itemPtr)
// Title:	generate a copy
// Description: this creates a copy of the dvd movie drama type.
// Parameters:	IItem * itemPtr
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Drama::genCopy(IItem * itemPtr)
{
	Drama *temp = static_cast<Drama*>(itemPtr);
	if (temp->getGenre() == 'D')
	{
		this->m_stock = temp->m_stock;
		this->m_director = temp->m_director;
		this->m_title = temp->m_title;
		this->m_yearReleased = temp->m_yearReleased;
	}
}

// --------------------------------------------------------------------------
// Function:	void Drama::buildDVD(char genre, ifstream & inputFileInventory)
// Title:	Build Drama DVD
// Description: createa drama movie type by assigning the correct attribute values
// based on what is read from the input file.
// Parameters:	char genre, ifstream & inputFileInventory
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Drama::buildDVD(char genre, ifstream & inputFileInventory)
{
	string comma = " ";

	// D, 10, Barry Levinson, Good Morning Vietnam, 1988
	// D, 10, Gus Van Sant, Good Will Hunting, 2000

	this->setGenreAbbrev(genre);
	getline(inputFileInventory, comma, ' ');
	inputFileInventory >> this->m_stock;
	getline(inputFileInventory, comma, ' ');
	getline(inputFileInventory, this->m_director, ',');
	getline(inputFileInventory, this->m_title, ',');
	inputFileInventory >> this->m_yearReleased;
}

// --------------------------------------------------------------------------
// Function:	bool Drama::operator==(IItem * itemPtr)
// Title:	overload equality operator
// Description: comapres for equality of the movie type between two drama objects
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Drama::operator==(IItem * itemPtr)
{
	bool equal = false;
	Drama *temp = static_cast<Drama*>(itemPtr);
	if (m_title == temp->getTitle() && m_director == temp->getDirector())
	{
		equal = true;
	}
	return equal;
}

// --------------------------------------------------------------------------
// Function:	bool Drama::operator<(IItem * itemPtr)
// Title:	overload less than operator
// Description: comapres for less than of the movie type between two drama objects
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Drama::operator<(IItem * itemPtr)
{
	bool return_value = false;
	Drama *temp = static_cast<Drama*>(itemPtr);

	if (this->getDirector() < temp->getDirector())
	{
		return_value = true;
	}
	else if (this->getDirector() == temp->getDirector())
	{
		if (this->getTitle() < temp->getTitle())
		{
			return_value = true;
		}
	}
	return return_value;
}

// --------------------------------------------------------------------------
// Function:	bool Drama::operator<(IItem * itemPtr)
// Title:	overload greater than operator
// Description: comapres for greater than of the movie type between two drama objects
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Drama::operator>(IItem * itemPtr)
{
	bool return_value = false;
	Drama *temp = static_cast<Drama*>(itemPtr);

	if (this->getDirector() > temp->getDirector())
	{
		return_value = true;
	}
	else if (this->getDirector() == temp->getDirector())
	{
		if (this->getTitle() > temp->getTitle())
		{
			return_value = true;
		}
	}
	return return_value;
}
