//-----------------------------------------------------------------------------
// File:	imedia.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The class defines a media type which is derived from the base class
// iitems. Imedia can hold release year, title, type of media. DVD inherits imedia
//-----------------------------------------------------------------------------

#include "imedia.h"

// --------------------------------------------------------------------------
// Function:	IMedia::~IMedia()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IMedia::~IMedia()
{
}

// --------------------------------------------------------------------------
// Function:	int IMedia::getYearReleased()
// Title:	accessor for m_yearReleased
// Description: gets the release year of the media type
// Parameters:	N/A
// Returns:	int
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int IMedia::getYearReleased()
{
	return m_yearReleased;
}

// --------------------------------------------------------------------------
// Function:	string IMedia::getTitle()
// Title:	accessor for m_title
// Description: gets the title of the media type
// Parameters:	N/A
// Returns:	string
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
string IMedia::getTitle()
{
	return m_title;
}

// --------------------------------------------------------------------------
// Function:	char IMedia::getMediaTypeAbbrev()
// Title:	accessor for m_mediaTypeAbbrev
// Description: gets the abbreviation of the media type. 'D' for DVD
// Parameters:	N/A
// Returns:	char
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
char IMedia::getMediaTypeAbbrev()
{
	return m_mediaTypeAbbrev;
}

// --------------------------------------------------------------------------
// Function:	void IMedia::setTitle(string title)
// Title:	mutator for m_title
// Description: set the title name of the media
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void IMedia::setTitle(string title)
{
	m_title = title;
}

// --------------------------------------------------------------------------
// Function:	void IMedia::setYearReleased(int yearReleased)
// Title:	mutator for m_yearReleased;
// Description: set the year the media was released
// Parameters:	int yearReleased
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void IMedia::setYearReleased(int yearReleased)
{
	int current_year = 2018;
	// Not sure if we wanna set upper or lower limits for year release
	if (yearReleased <= current_year)
	{
		m_yearReleased = yearReleased;
	}
}

// --------------------------------------------------------------------------
// Function:	void IMedia::setMediaTypeAbbrev(char mediaTypeAbbrev)
// Title:	mutator for mediaTypeAbbrev;
// Description: set the media type abbreviation. D for DVD
// Parameters:	char mediaTypeAbbrev
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void IMedia::setMediaTypeAbbrev(char mediaTypeAbbrev)
{
	// Not sure if we are error checking this or not for anything besides 'D'
	m_mediaTypeAbbrev = mediaTypeAbbrev;
}

