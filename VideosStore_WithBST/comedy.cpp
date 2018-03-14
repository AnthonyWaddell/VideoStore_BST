//-----------------------------------------------------------------------------
// File:	comedy.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class creates an object of a DVD movie type Comedy. It sets
// the attributes by reading the rest of the line. The class can also print out
// the entire data of that movie once an object of that movie has been created.
//-----------------------------------------------------------------------------

#include "comedy.h"

// --------------------------------------------------------------------------
// Function:	Comedy::~Comedy()
// Title:	Desctructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
Comedy::~Comedy()
{
}

// --------------------------------------------------------------------------
// Function:	void Comedy::display()
// Title:	display the dvd comedy attributes
// Description: using iostream to print out each attribute of the movie
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Comedy::display() const
{
	cout << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_yearReleased << endl;
}

// --------------------------------------------------------------------------
//	Display function, really not sure if this is what this is supposed to do?
// Function:	void Comedy::genDisplay(string & genDisplayString)
// Title:	Display
// Description: Display
// Parameters:	string & genDisplayString
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Comedy::genDisplay(string & genDisplayString)
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
// Function:	void Comedy::genCopy(IItem * itemPtr)
// Title:	Generate a copy of the movie
// Description: Createa copy of the itemptr using the movie attributes
// Parameters:	IItem * itemPtr
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Comedy::genCopy(IItem * itemPtr)
{
	Comedy *temp = static_cast<Comedy*>(itemPtr);
	if (temp->getGenre() == 'F')
	{

		this->m_stock = temp->m_stock;
		this->m_director = temp->m_director;
		this->m_title = temp->m_title;
		this->m_yearReleased = temp->m_yearReleased;
	}
}

// --------------------------------------------------------------------------
// Function:	void Comedy::buildDVD(char genre, std::ifstream & inputFileInventory)
// Title:	Build a comedy DVD
// Description: Make a dvd object by reading the rest of the line from the input file
// and assigning the correct values
// Parameters:	char genre, std::ifstream & inputFileInventory
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void Comedy::buildDVD(char genre, std::ifstream & inputFileInventory)
{
	//F, 10, Nora Ephron, Sleepless in Seattle, 1993
	string comma = " ";

	this->setGenreAbbrev(genre);
	getline(inputFileInventory, comma, ' ');
	inputFileInventory >> this->m_stock;
	getline(inputFileInventory, comma, ' ');
	//maybe a cin.get() or cin.ignore() to eat up space/comma
	getline(inputFileInventory, this->m_director, ',');
	getline(inputFileInventory, this->m_title, ',');
	//maybe a cin.get() or cin.ignore() to eat up the space/comma
	inputFileInventory >> this->m_yearReleased;
}

// --------------------------------------------------------------------------
// Function:	bool Comedy::operator==(IItem * itemPtr)
// Title:	compare comedy types
// Description: check the comedy dvd to see if it is the same title and release year
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Comedy::operator==(IItem * itemPtr)
{
	bool equal = false;
	Comedy *temp = static_cast<Comedy*>(itemPtr);
	if (m_title == temp->getTitle() && m_yearReleased == temp->getYearReleased())
	{
		equal = true;
	}
	return equal;
}

// --------------------------------------------------------------------------
// Function:	bool Comedy::operator<(IItem * itemPtr)
// Title:	compare comedy types
// Description: return true if the title of the movie is less than or if the 
// release year is less than the one being compared to.
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Comedy::operator<(IItem * itemPtr)
{
	bool return_value = false;
	Comedy *temp = static_cast<Comedy*>(itemPtr);

	if (this->getTitle() < temp->getTitle())
	{
		return_value = true;
	}
	else if (this->getTitle() == temp->getTitle())
	{
		if (this->getYearReleased() < temp->getYearReleased())
		{
			return_value = true;
		}
	}
	return return_value;

}

// --------------------------------------------------------------------------
// Function:	bool Comedy::operator>(IItem * itemPtr)
// Title:	compare comedy types
// Description: return true if the title of the movie is greater than or if the 
// release year is greater than the one being compared to.
// Parameters:	IItem * itemPtr
// Returns:	bool
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
bool Comedy::operator>(IItem * itemPtr)
{
	bool return_value = false;
	Comedy *temp = static_cast<Comedy*>(itemPtr);

	if (this->getTitle() > temp->getTitle())
	{
		return_value = true;
	}
	else if (this->getTitle() == temp->getTitle())
	{
		if (this->getYearReleased() > temp->getYearReleased())
		{
			return_value = true;
		}
	}
	return return_value;
}
