#include "drama.h"

// --------------------------------------------------------------------------
//	Destructor
// --------------------------------------------------------------------------
Drama::~Drama()
{
}

// --------------------------------------------------------------------------
//	display object information to designated output stream
// --------------------------------------------------------------------------
void Drama::display() const
{
	cout << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_yearReleased << endl;
}

// --------------------------------------------------------------------------
//	create string with relevant properties of this dvd
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
//	copy properties of itemPtr to *this
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
//	Fill relevant properties of a Drama DVD with information from input file
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
//	Overloaded boolean equality operator, not sure if we are checking anything other than title and director
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
//	overloaded less than operator
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
//	overloaded greater than operator
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
