#include "comedy.h"

// --------------------------------------------------------------------------
//	Destructor
// --------------------------------------------------------------------------
Comedy::~Comedy()
{
}

// --------------------------------------------------------------------------
//	Display function to output stream
// --------------------------------------------------------------------------
void Comedy::display() const
{
	cout << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_yearReleased << endl;
}

// --------------------------------------------------------------------------
//	Display function, really not sure if this is what this is supposed to do?
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
//	copy properties of itemPtr to *this
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
//	Build a comedy dvd
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
//	Overloaded boolean equality operator, not sure if we are checking anything other than title and director
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
//	overloaded less than operator
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
//	overloaded greater than operator
// --------------------------------------------------------------------------
bool Comedy::operator>(IItem * itemPtr)
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
