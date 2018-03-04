#include "classical.h"

// --------------------------------------------------------------------------
//	Destructor
// --------------------------------------------------------------------------
Classical::~Classical()
{
}

// --------------------------------------------------------------------------
//	Display function to output stream
// --------------------------------------------------------------------------
void Classical::display(ostream & outStream) const
{
	outStream << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_majorActorFirstName << " " <<
		m_majorActorLastName << " " << m_monthReleased << " " <<
		m_yearReleased << endl;
}

// --------------------------------------------------------------------------
//	Display function, really not sure if this is what this is supposed to do?
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
//	copy properties of itemPtr to *this
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
//	Build a classical dvd
// --------------------------------------------------------------------------
void Classical::buildDVD(char genre, ifstream & inputFileInventory)
{
	// This needs error handling


	//C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
	this->setGenreAbbrev(genre);
	inputFileInventory >> this->m_stock;
	//maybe a cin.get() or cin.ignore() to eat up space/comma
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
//	Overloaded boolean equality operator, not sure if we are checking anything other than title and director
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
//	overloaded less than operator
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
//	overloaded greater than operator
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
//	accessor for m_monthReleased
// --------------------------------------------------------------------------
int Classical::getMonthReleased()
{
	return m_monthReleased;
}

// --------------------------------------------------------------------------
//	accessor for m_majorActorFirstName
// --------------------------------------------------------------------------
string Classical::getMajorActorFirstName()
{
	return m_majorActorFirstName;
}

// --------------------------------------------------------------------------
//	accessor for m_majorActorLastName
// --------------------------------------------------------------------------
string Classical::getMajorActorLastName()
{
	return m_majorActorLastName;
}

// --------------------------------------------------------------------------
// mutator for m_monthReleased
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
//	mutator for m_majorActorFirstName
// --------------------------------------------------------------------------
void Classical::setMajorActorFirstName(string firstName)
{
	m_majorActorFirstName = firstName;
}

// --------------------------------------------------------------------------
//	mutator for m_majorActorLastName
// --------------------------------------------------------------------------
void Classical::setMajorActorLastName(string lastName)
{
	m_majorActorLastName = lastName;
}

